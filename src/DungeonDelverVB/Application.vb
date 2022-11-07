Module Application
    Friend Sub Initialize()
    End Sub

    Friend Sub Draw()
    End Sub

    Friend Sub CleanUp()
    End Sub

    Friend Function Updater(command As Char) As Boolean
        Return command <> "."c
    End Function
End Module
