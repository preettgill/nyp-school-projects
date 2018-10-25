'Project: Recording Cheques and Deposits 
'Name:Harpreet Kaur & Lim Wen Zheng, Lynnette
'AdminNo:071545Y & 075737L
'Module Grp:IT1845-E1

Option Explicit On
Option Strict On
Imports System.Data
Imports System.Globalization




Public Class chequesForm
  
    Private Sub clearButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles clearButton.Click
        ' clear input 
        Call Clear()
        'txtAccount.Clear()
        'txtChequeNo.Clear()
        'txtDate.Clear()
        'txtDeposit.Clear()
        'txtWithdrawal.Clear()
        'LabelAmt.Text = ""
        'LabelBalance.Text = ""
        'txtAccount.Focus()
    End Sub
    Sub Clear()
        txtAccount.Clear()
        txtChequeNo.Clear()
        txtDate.Clear()
        txtDeposit.Clear()
        txtWithdrawal.Clear()
        LabelAmt.Text = String.Empty
        LabelBalance.Text = String.Empty
        lblfirstAmt.Text = String.Empty
        lblinitizeAmt.Text = String.Empty
        txtAccount.Focus()
    End Sub

    Private Sub backButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles backButton.Click
        ' back to main form
        MainForm.Show()
        Me.Hide()

    End Sub

    Private Sub LogoutToolStripMenuItem_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles LogoutToolStripMenuItem.Click
        ' user to logout
        If MessageBox.Show("Do you want to logout", "Logout", MessageBoxButtons.YesNoCancel, System.Windows.Forms.MessageBoxIcon.Warning) = Windows.Forms.DialogResult.Yes Then
            LoginForm.Show()
            Me.Hide()
        End If
    End Sub

    Private Sub ExitToolStripMenuItem1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ExitToolStripMenuItem1.Click
        'exit
        If MessageBox.Show("Do you want to exit?", "Are you sure?", MessageBoxButtons.YesNoCancel, System.Windows.Forms.MessageBoxIcon.Warning) = Windows.Forms.DialogResult.Yes Then
            LoginForm.Close()
            MainForm.Close()
            SplashScreenForm.Close()
            Me.Close()
        End If

        'Me.Close()
        'End

    End Sub

    Private Sub chequesForm_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'TODO: This line of code loads data into the 'Banking_SystemDataSet.Cheques' table. You can move, or remove it, as needed.
        Me.ChequesTableAdapter.Fill(Me.Banking_SystemDataSet1.Cheques)

    End Sub

    Private Sub btnprev_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnprev.Click
        ' previous data in dataset
        ChequesBindingSource.MovePrevious()
    End Sub

    Private Sub btnNext_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnNext.Click
        'next data in dataset
        ChequesBindingSource.MoveNext()
    End Sub

    Private Sub delButton_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles delButton.Click
        'delete data from dataset
        If MessageBox.Show("Do you want to delete", "Are you sure?", MessageBoxButtons.YesNoCancel, System.Windows.Forms.MessageBoxIcon.Warning) = Windows.Forms.DialogResult.Yes Then
            ChequesBindingSource.RemoveCurrent()
            Me.ChequesTableAdapter.Update(Me.Banking_SystemDataSet1.Cheques)
        End If
    End Sub

    Private Sub SaveToolStripMenuItem1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles SaveToolStripMenuItem1.Click
        ' sava data in dataset
        Call save()

    End Sub

    Private Sub Save_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnSave.Click

        Call save()


    End Sub
    Private Sub save()
        'declare
        Const title1 As String = "Saving Failed"

        'Check empty data or validate data
        If String.IsNullOrEmpty(txtAccount.Text) Or IsNumeric(txtAccount.Text) = False Then
            MessageBox.Show("Please fill in the account details in number and make sure all required details are filled ", _
             title1, MessageBoxButtons.OK, _
             MessageBoxIcon.Exclamation)
            txtAccount.Focus()
        End If
        If String.IsNullOrEmpty(txtChequeNo.Text) Or IsNumeric(txtChequeNo.Text) = False Then
            MessageBox.Show("Please fill in the ChequeNo detail in number", _
             title1, MessageBoxButtons.OK, _
           MessageBoxIcon.Exclamation)
            txtChequeNo.Focus()
        End If
        If String.IsNullOrEmpty(txtDate.Text) Then
            MessageBox.Show("Please fill in the Date", _
            title1, MessageBoxButtons.OK, _
            MessageBoxIcon.Exclamation)
            txtDate.Focus()
        End If

        If Me.Validate Then
            Me.ChequesBindingSource.EndEdit()
            Me.ChequesTableAdapter.Update(Me.Banking_SystemDataSet1.Cheques)
            DataGridView1.Refresh()
        Else
            System.Windows.Forms.MessageBox.Show(Me, _
            "Validation errors occurred.", "Save", _
            System.Windows.Forms.MessageBoxButtons.OK, _
            System.Windows.Forms.MessageBoxIcon.Warning)
        End If



    End Sub


    Private Sub btnDeposit_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnDeposit.Click

        Call deposit()

    End Sub

    Private Sub deposit()
        'Calculate deposit and show new balance 

        'declare
        Dim account As Integer
        Dim deposit, newBal As Decimal
        Dim temppreBal As Decimal
        Const Title As String = "New Balance"
        Dim isConverted, isConverted2 As Boolean


        If String.IsNullOrEmpty(txtDeposit.Text) Then
            txtDeposit.Text = "0"
        End If

        isConverted = Decimal.TryParse(txtDeposit.Text, NumberStyles.AllowThousands, NumberFormatInfo.CurrentInfo, deposit)
        isConverted2 = Integer.TryParse(txtAccount.Text, account)

        If isConverted = True AndAlso isConverted = True Then
            If deposit > 0 Then
                temppreBal = CDec(lblinitizeAmt.Text)
                newBal = CDec(temppreBal + CDbl(txtDeposit.Text))
                'LabelAmt.Text = CStr(temppreBal)
                LabelAmt.Text = temppreBal.ToString("C2")
            End If
            MessageBox.Show("Account No " & account & " has the New Balance of $" & newBal, _
                              Title, MessageBoxButtons.OK, _
                               MessageBoxIcon.Information)
            'LabelBalance.Text = CStr(newBal)
            LabelBalance.Text = newBal.ToString("C2")
            DataGridView1.Refresh()
        End If

    End Sub

    Private Sub withdrawal()
        'Calculate withdrawal and show new balance


        'declare
        Dim account As Integer
        Dim withdrawal, newBal As Decimal
        Dim tempBal As Decimal

        Const Title As String = "New Balance"
        Dim isConverted, isConverted2 As Boolean

        If String.IsNullOrEmpty(txtWithdrawal.Text) Then
            txtWithdrawal.Text = "0"
        End If

        isConverted = Decimal.TryParse(txtWithdrawal.Text, NumberStyles.AllowThousands, NumberFormatInfo.CurrentInfo, withdrawal)
        isConverted2 = Integer.TryParse(txtAccount.Text, account)


        If isConverted = True AndAlso isConverted = True Then

            If withdrawal > 0 Then
                tempBal = CDec(lblfirstAmt.Text)
                newBal = CDec(tempBal - CDbl(txtWithdrawal.Text))
                'LabelAmt.Text = CStr(tempBal)
                LabelAmt.Text = tempBal.ToString("C2")

            End If
            MessageBox.Show("Account No " & account & " has the New Balance of $" & newBal, _
                              Title, MessageBoxButtons.OK, _
                              MessageBoxIcon.Information)

            'LabelBalance.Text = CStr(newBal)
            LabelBalance.Text = newBal.ToString("C2")
            DataGridView1.Refresh()


        End If
    End Sub

    Private Sub btnWithdrawal_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles btnWithdrawal.Click
        Call withdrawal()

    End Sub
End Class