# ForceSim

Touch firmware의 **Pressure 계산 알고리즘을 그대로 재현하여 로그 데이터를 기반으로 결과를 확인하는 시뮬레이터**입니다.

---

# 1. 실행 방법

⚠️ **반드시 `x64` 플랫폼으로 실행해야 합니다.**

Visual Studio 상단에서 아래와 같이 설정 후 실행하세요.

```
Solution Platform : x64
```

알고리즘 DLL(`ForceAlgoDll`)이 **x64로 빌드되기 때문에** AnyCPU / x86 실행 시 정상 동작하지 않습니다.

---

# 2. 알고리즘 수정 위치

Pressure 계산 알고리즘을 수정하려면 아래 **3개의 파일만 수정하면 됩니다.**

```
Force_Calibration.c
Config.h
Force_Rawdata_point_18by13.h
```

설명:

| 파일                             | 역할                               |
| ------------------------------ | -------------------------------- |
| `Force_Calibration.c`          | Pressure 계산 알고리즘                 |
| `Config.h`                     | 매크로 / 타입 정의                      |
| `Force_Rawdata_point_18by13.h` | 참조 데이터 (FSR Zone / Weight Table) |

이 외 프로젝트 코드는 **시뮬레이터 UI 및 로그 처리용**이므로 수정할 필요 없습니다.

---

# 3. 설정 파일 (`setting.conf`)

시뮬레이터 동작은 `setting.conf` 파일에서 조절할 수 있습니다.

예시:

```
[touchpad]
width=2316
height=1636

[section]
cols=16
rows=12

[speed]
sec=0.02
```

설정 설명:

| 항목                | 설명         |
| ----------------- | ---------- |
| `touchpad.width`  | 터치패드 X 해상도 |
| `touchpad.height` | 터치패드 Y 해상도 |
| `section.cols`    | 표 X 분할 수   |
| `section.rows`    | 표 Y 분할 수   |
| `speed.sec`       | 로그 재생 속도   |

---

# 4. Scaler 처리 규칙

로그 첫 줄에 Scaler 정보가 포함되어 있을 수 있습니다.

예시:

```
Scaler1:282,Scaler2:268,Scaler3:295,Scaler4:279,Scaler5:343,Scaler6:297
```

동작 규칙:

* Scaler가 존재하면 → 해당 값 사용
* **Scaler가 없으면 → 기본값 `300` 사용**

```
default scaler = 300
```

---

# 5. 로그 파일

로그 파일은 `logs` 폴더에 위치합니다.

```
logs/
 └ log.txt
```

UI에서 파일을 선택하여 시뮬레이션을 실행할 수 있습니다.

---

# Summary

| 항목      | 위치                    |
| ------- | --------------------- |
| 실행 플랫폼  | **x64**               |
| 알고리즘 수정 | `Force_Calibration.c` |
| 설정 변경   | `setting.conf`        |
| 로그 파일   | `logs/`               |

---

Force firmware 알고리즘을 빠르게 테스트하기 위한 **경량 시뮬레이터**입니다.
