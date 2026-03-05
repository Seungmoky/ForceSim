using System.Runtime.InteropServices;

internal static class ForceNative
{
    private const string DllName = "ForceAlgoDll.dll";

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    internal static extern void Force_SetScaler(short[] scaler6);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    internal static extern short Force_EstimateWeight(short x, short y, short[] sensor6);
}