Imports System.Runtime.InteropServices
Module Program
    Const SCREEN_WIDTH = 1280
    Const SCREEN_HEIGHT = 720
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
    End Structure
    Declare Function SDL_WaitEvent Lib "SDL2.dll" (
                                                  ByRef [event] As SDL_Event) As Integer
    Declare Sub SDL_DestroyRenderer Lib "SDL2.dll" (ByVal renderer As IntPtr)
    Declare Sub SDL_DestroyWindow Lib "SDL2.dll" (ByVal window As IntPtr)
    Sub Main(args As String())
        If SDL_Init(&H10F231) = 0 Then
            Dim window As IntPtr = IntPtr.Zero
            Dim renderer As IntPtr = IntPtr.Zero
            If SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, window, renderer) = 0 Then
                Dim [event] As New SDL_Event
                Do
                    SDL_RenderClear(renderer)
                    SDL_RenderPresent(renderer)
                    If SDL_WaitEvent([event]) = 1 Then
                        If [event].type = 256 Then
                            Exit Do
                        End If
                    End If
                Loop
                If renderer <> IntPtr.Zero Then
                    SDL_DestroyRenderer(renderer)
                    renderer = IntPtr.Zero
                End If
                If window <> IntPtr.Zero Then
                    SDL_DestroyWindow(window)
                    window = IntPtr.Zero
                End If
            End If
            SDL_Quit()
        End If
    End Sub
End Module
