Imports System.Runtime.InteropServices
Module Program
    Const SCREEN_WIDTH = 1280
    Const SCREEN_HEIGHT = 720
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
