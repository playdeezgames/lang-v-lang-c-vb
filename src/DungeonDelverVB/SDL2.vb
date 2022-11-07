Imports System.Runtime.InteropServices

Module SDL2
    Declare Function SDL_Init Lib "SDL2.dll" (flags As UInt32) As Integer
    Declare Function SDL_CreateWindowAndRenderer Lib "SDL2.dll" (
                                                                ByVal width As Integer,
                                                                ByVal height As Integer,
                                                                ByVal window_flags As UInt32,
                                                                ByRef window As IntPtr,
                                                                ByRef renderer As IntPtr) As Integer
    Declare Function SDL_RenderClear Lib "SDL2.dll" (ByVal renderer As IntPtr) As Integer
    Declare Function SDL_RenderPresent Lib "SDL2.dll" (ByVal renderer As IntPtr) As Integer
    Declare Sub SDL_Quit Lib "SDL2.dll" ()
    <StructLayout(LayoutKind.Explicit, Size:=56)>
    Structure SDL_Event
        <FieldOffset(0)>
        Public type As UInt32
        <FieldOffset(20)>
        Public sym As UInt32
    End Structure
    Declare Function SDL_WaitEvent Lib "SDL2.dll" (
                                                  ByRef [event] As SDL_Event) As Integer
    Declare Sub SDL_DestroyRenderer Lib "SDL2.dll" (ByVal renderer As IntPtr)
    Declare Sub SDL_DestroyWindow Lib "SDL2.dll" (ByVal window As IntPtr)
End Module
