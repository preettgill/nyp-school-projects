'Project: Recording Cheques and Deposits 
'Name:Harpreet Kaur & Lim Wen Zheng, Lynnette
'AdminNo:071545Y &  075737L
'Module Grp:IT1845-E1


Option Explicit On
Option Strict On

Public Class MainForm

    Private Sub AboutToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles AboutToolStripMenuItem.Click
        ' About the programme

        MessageBox.Show("This programme is done by Preet and Nettez.! Copyright 2008!", " About", MessageBoxButtons.OK, MessageBoxIcon.Information)

    End Sub

    Private Sub logoutButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles logoutButton.Click
        ' logout

        If MessageBox.Show("Do you want to logout", "Logout", MessageBoxButtons.YesNoCancel, System.Windows.Forms.MessageBoxIcon.Warning) = Windows.Forms.DialogResult.Yes Then
            LoginForm.Show()
            Me.Hide()
        End If

    End Sub

    Private Sub ExitToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ExitToolStripMenuItem.Click
       
        'Me.Close()
        End

    End Sub

    Private Sub chequesButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles chequesButton.Click
        ' show cheque form
        chequesForm.Show()
        Me.Hide()

    End Sub

End Class