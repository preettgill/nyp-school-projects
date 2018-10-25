'Project: Recording Cheques and Deposits 
'Name:Harpreet Kaur & Lim Wen Zheng, Lynnette
'AdminNo:071545Y &  075737L
'Module Grp:IT1845-E1

Option Explicit On
Option Strict On

Public Class LoginForm

    Private Sub exitButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles exitButton.Click
        Me.Close()

    End Sub

    Private Sub LoginButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles LoginButton.Click

        'user to enter password  

        'declare
        Const title As String = "Login Failed"

        userTextBox.Focus()
        If userTextBox.Text = "" And psdTextBox.Text = "" Then
            MessageBox.Show("Either username or password is empty", title, MessageBoxButtons.OK)
            userTextBox.Focus()

        ElseIf userTextBox.Text = "Admin" And psdTextBox.Text = "password" Then
            MessageBox.Show("Welcome Admin", "Login Successful", MessageBoxButtons.OK)
            Me.Hide()
            userTextBox.Text = ""
            psdTextBox.Text = ""
            MainForm.Show()

        Else

            MessageBox.Show("Either Username or password is wrong", title, MessageBoxButtons.RetryCancel)
            userTextBox.Focus()
            psdTextBox.Text = ""
        End If

    End Sub
    Private Sub LoginForm_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        ' show splash srceen form
        SplashScreenForm.ShowDialog()

    End Sub
End Class
