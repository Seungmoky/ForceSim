using System;
using System.ComponentModel;
using System.Runtime.InteropServices;

internal static class ForceNative
{
    // kernel32: 동적 DLL 로드용
    [DllImport("kernel32.dll", SetLastError = true, CharSet = CharSet.Auto)]
    private static extern IntPtr LoadLibrary(string lpFileName);

    [DllImport("kernel32.dll", SetLastError = true)]
    private static extern IntPtr GetProcAddress(IntPtr hModule, string lpProcName);

    // 함수 시그니처 델리게이트
    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    private delegate void SetScalerDelegate(short[] scaler6);

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    private delegate short EstimateWeightDelegate(short x, short y, short[] sensor6);

    private static SetScalerDelegate _setScaler;
    private static EstimateWeightDelegate _estimateWeight;
    private static bool _initialized = false;

    // 외부 DLL 경로를 지정해 동적 로드 (복사 없이 직접 로드)
    internal static void Initialize(string dllPath)
    {
        var hModule = LoadLibrary(dllPath);
        if (hModule == IntPtr.Zero)
            throw new Win32Exception(Marshal.GetLastWin32Error(), $"DLL 로드 실패: {dllPath}");

        _setScaler = Marshal.GetDelegateForFunctionPointer<SetScalerDelegate>(
            GetProcAddress(hModule, "Force_SetScaler"));
        _estimateWeight = Marshal.GetDelegateForFunctionPointer<EstimateWeightDelegate>(
            GetProcAddress(hModule, "Force_EstimateWeight"));
        _initialized = true;
    }

    internal static void Force_SetScaler(short[] scaler6)
    {
        if (_initialized)
            _setScaler(scaler6);
        else
            Force_SetScaler_Static(scaler6);
    }

    internal static short Force_EstimateWeight(short x, short y, short[] sensor6)
    {
        if (_initialized)
            return _estimateWeight(x, y, sensor6);
        return Force_EstimateWeight_Static(x, y, sensor6);
    }

    // 기본 정적 DllImport (external_dll 미사용 시)
    [DllImport("ForceAlgoDll.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Force_SetScaler")]
    private static extern void Force_SetScaler_Static(short[] scaler6);

    [DllImport("ForceAlgoDll.dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "Force_EstimateWeight")]
    private static extern short Force_EstimateWeight_Static(short x, short y, short[] sensor6);
}
