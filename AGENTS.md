# AGENTS.md

## 목적
이 문서는 `ForceSim` 저장소에서 작업하는 에이전트/개발자를 위한 빠른 실행 가이드입니다.
핵심 목표는 **Force 알고리즘 수정 -> 빌드 -> 시뮬레이션 확인**을 안전하고 빠르게 반복하는 것입니다.

## 저장소 구조
- `ForceSim.sln`: 전체 솔루션
- `ForceSim.App/`: WPF 시뮬레이터 UI (.NET Framework 4.8)
- `ForceAlgoDll/`: 네이티브 알고리즘 DLL (C/C++)
- `ForceConsole/`: 콘솔 기반 디버그 러너 (C)
- `logs/`: 입력 로그 파일(.txt) 보관 폴더
- `setting.conf`: 실행/맵핑/속도/디버그 설정

## 필수 규칙
- 반드시 `x64`로 빌드/실행할 것
- 알고리즘 변경은 우선 아래 3개 파일에서 수행
  - `ForceAlgoDll/Force_Calibration.c`
  - `ForceAlgoDll/Config.h`
  - `ForceAlgoDll/Force_Rawdata_point_18by13.h`
- UI 동작 로직 변경은 `ForceSim.App/MainWindow.xaml(.cs)`에서 수행

## 빌드/실행 흐름
1. `ForceAlgoDll` 빌드
2. DLL PostBuild에서 `ForceSim.App/bin/x64/<Config>/ForceAlgoDll.dll`로 자동 복사
3. `ForceSim.App` 실행
4. 앱이 `ForceNative` P/Invoke로 `ForceAlgoDll.dll`의 `Force_SetScaler`, `Force_EstimateWeight` 호출

참고:
- 솔루션에서 `ForceSim.App`은 `ForceAlgoDll`에 의존하도록 설정되어 있음
- `ForceConsole`은 별도 디버그 경로로 사용 가능

## 엔트리 포인트
- UI 시작점: `ForceSim.App/App.xaml.cs` (`OnStartup`)
- UI 메인 처리: `ForceSim.App/MainWindow.xaml.cs`
- 네이티브 브릿지: `ForceSim.App/ForceNative.cs`
- DLL API 시작점: `ForceAlgoDll/ForceApi.c`
- 콘솔 시작점: `ForceConsole/main.c`

## setting.conf 규칙
- 주요 섹션
  - `[touchpad]`: `width`, `height`
  - `[section]`: `cols`, `rows` (필요 시 `flipY`)
  - `[speed]`: `sec`
  - `[debug]`: `enable`, `log_file`
- `debug.enable=1`이면 WPF 앱은 시작 직후 종료되고 콘솔 경로 사용이 의도된 구성

## 변경 작업 가이드
- 알고리즘 수치/테이블 조정:
  - `Force_Calibration.c` 우선 수정
  - 필요 시 `Config.h`, `Force_Rawdata_point_18by13.h` 동시 조정
- 로그 파싱 변경:
  - WPF: `ForceSim.App/LogParser.cs`
  - Console: `ForceConsole/log_parser.c`
- UI 표시/맵핑 변경:
  - `MainWindow.xaml`, `MainWindow.xaml.cs`

## 검증 체크리스트
1. `x64 Debug`로 솔루션 빌드 성공
2. `ForceSim.App/bin/x64/Debug/ForceAlgoDll.dll` 갱신 확인
3. `logs/*.txt` 파일 로드 및 Start 실행 확인
4. 스케일러 줄 존재/부재 모두 동작 확인
5. 알고리즘 변경 시 `delta`/heat-map 변화 확인

## 커밋 가이드
- 설정/실험성 값 변경과 알고리즘 변경은 분리 커밋 권장
- 로그 샘플 대용량 파일은 불필요 시 커밋 제외
- 변경 이유를 커밋 메시지에 명시
  - 예: `Force_Calibration: adjust zone weight interpolation for edge press`
