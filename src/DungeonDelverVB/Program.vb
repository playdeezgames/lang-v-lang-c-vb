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
                        Select Case [event].type
                            Case 256
                                Exit Do
                            Case 768
                                If Not HandleKeyDown([event].sym) Then
                                    Exit Do
                                End If
                        End Select
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
    Private Function HandleKeyDown(sym As UInteger) As Boolean
        Select Case sym
            Case 46, 1073741923, 127
                Return HandleCommand("."c)
            Case 48, 1073741922, 1073741897
                Return HandleCommand("0"c)
            Case 49, 1073741913, 1073741901
                Return HandleCommand("1"c)
            Case 50, 1073741914, 1073741905
                Return HandleCommand("2"c)
            Case 51, 1073741915, 1073741902
                Return HandleCommand("3"c)
            Case 52, 1073741916, 1073741904
                Return HandleCommand("4"c)
            Case 53, 1073741917
                Return HandleCommand("5"c)
            Case 54, 1073741918, 1073741903
                Return HandleCommand("6"c)
            Case 55, 1073741919, 1073741898
                Return HandleCommand("7"c)
            Case 56, 1073741920, 1073741906
                Return HandleCommand("8"c)
            Case 57, 1073741921, 1073741899
                Return HandleCommand("9"c)
            Case Else
                Return True
        End Select
    End Function

    Private Function HandleCommand(command As Char) As Boolean
        Return command <> "."c
    End Function
End Module
