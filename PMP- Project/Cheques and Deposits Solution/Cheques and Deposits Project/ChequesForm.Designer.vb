<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class chequesForm
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container
        Me.GroupBox1 = New System.Windows.Forms.GroupBox
        Me.lblfirstAmt = New System.Windows.Forms.Label
        Me.ChequesBindingSource = New System.Windows.Forms.BindingSource(Me.components)
        Me.Banking_SystemDataSet1 = New Cheques_and_Deposits_Project.Banking_SystemDataSet1
        Me.lblinitizeAmt = New System.Windows.Forms.Label
        Me.txtWithdrawal = New System.Windows.Forms.TextBox
        Me.txtDeposit = New System.Windows.Forms.TextBox
        Me.txtDate = New System.Windows.Forms.TextBox
        Me.txtChequeNo = New System.Windows.Forms.TextBox
        Me.LabelBalance = New System.Windows.Forms.Label
        Me.LabelAmt = New System.Windows.Forms.Label
        Me.txtAccount = New System.Windows.Forms.TextBox
        Me.Label8 = New System.Windows.Forms.Label
        Me.Label7 = New System.Windows.Forms.Label
        Me.Label6 = New System.Windows.Forms.Label
        Me.Label5 = New System.Windows.Forms.Label
        Me.Label4 = New System.Windows.Forms.Label
        Me.Label3 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.GroupBox2 = New System.Windows.Forms.GroupBox
        Me.btnWithdrawal = New System.Windows.Forms.Button
        Me.btnDeposit = New System.Windows.Forms.Button
        Me.btnSave = New System.Windows.Forms.Button
        Me.delButton = New System.Windows.Forms.Button
        Me.clearButton = New System.Windows.Forms.Button
        Me.backButton = New System.Windows.Forms.Button
        Me.btnNext = New System.Windows.Forms.Button
        Me.btnprev = New System.Windows.Forms.Button
        Me.MenuStrip = New System.Windows.Forms.MenuStrip
        Me.SaveToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
        Me.SaveToolStripMenuItem1 = New System.Windows.Forms.ToolStripMenuItem
        Me.LogoutToolStripMenuItem = New System.Windows.Forms.ToolStripMenuItem
        Me.ExitToolStripMenuItem1 = New System.Windows.Forms.ToolStripMenuItem
        Me.ToolTip1 = New System.Windows.Forms.ToolTip(Me.components)
        Me.DataGridView1 = New System.Windows.Forms.DataGridView
        Me.DateDataGridViewTextBoxColumn = New System.Windows.Forms.DataGridViewTextBoxColumn
        Me.ChequeNoDataGridViewTextBoxColumn = New System.Windows.Forms.DataGridViewTextBoxColumn
        Me.DepositAmountDataGridViewTextBoxColumn = New System.Windows.Forms.DataGridViewTextBoxColumn
        Me.WithdrawalAmountDataGridViewTextBoxColumn = New System.Windows.Forms.DataGridViewTextBoxColumn
        Me.AccountNoDataGridViewTextBoxColumn = New System.Windows.Forms.DataGridViewTextBoxColumn
        Me.AmountInBankDataGridViewTextBoxColumn = New System.Windows.Forms.DataGridViewTextBoxColumn
        Me.ChequesTableAdapter = New Cheques_and_Deposits_Project.Banking_SystemDataSet1TableAdapters.ChequesTableAdapter
        Me.GroupBox1.SuspendLayout()
        CType(Me.ChequesBindingSource, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.Banking_SystemDataSet1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.GroupBox2.SuspendLayout()
        Me.MenuStrip.SuspendLayout()
        CType(Me.DataGridView1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'GroupBox1
        '
        Me.GroupBox1.Controls.Add(Me.lblfirstAmt)
        Me.GroupBox1.Controls.Add(Me.lblinitizeAmt)
        Me.GroupBox1.Controls.Add(Me.txtWithdrawal)
        Me.GroupBox1.Controls.Add(Me.txtDeposit)
        Me.GroupBox1.Controls.Add(Me.txtDate)
        Me.GroupBox1.Controls.Add(Me.txtChequeNo)
        Me.GroupBox1.Controls.Add(Me.LabelBalance)
        Me.GroupBox1.Controls.Add(Me.LabelAmt)
        Me.GroupBox1.Controls.Add(Me.txtAccount)
        Me.GroupBox1.Controls.Add(Me.Label8)
        Me.GroupBox1.Controls.Add(Me.Label7)
        Me.GroupBox1.Controls.Add(Me.Label6)
        Me.GroupBox1.Controls.Add(Me.Label5)
        Me.GroupBox1.Controls.Add(Me.Label4)
        Me.GroupBox1.Controls.Add(Me.Label3)
        Me.GroupBox1.Controls.Add(Me.Label2)
        Me.GroupBox1.ForeColor = System.Drawing.Color.White
        Me.GroupBox1.Location = New System.Drawing.Point(27, 40)
        Me.GroupBox1.Name = "GroupBox1"
        Me.GroupBox1.Size = New System.Drawing.Size(419, 259)
        Me.GroupBox1.TabIndex = 0
        Me.GroupBox1.TabStop = False
        Me.GroupBox1.Text = "Input Data"
        '
        'lblfirstAmt
        '
        Me.lblfirstAmt.DataBindings.Add(New System.Windows.Forms.Binding("Text", Me.ChequesBindingSource, "Amount In Bank", True))
        Me.lblfirstAmt.ForeColor = System.Drawing.Color.Black
        Me.lblfirstAmt.Location = New System.Drawing.Point(137, 167)
        Me.lblfirstAmt.Name = "lblfirstAmt"
        Me.lblfirstAmt.Size = New System.Drawing.Size(71, 14)
        Me.lblfirstAmt.TabIndex = 15
        '
        'ChequesBindingSource
        '
        Me.ChequesBindingSource.DataMember = "Cheques"
        Me.ChequesBindingSource.DataSource = Me.Banking_SystemDataSet1
        '
        'Banking_SystemDataSet1
        '
        Me.Banking_SystemDataSet1.DataSetName = "Banking_SystemDataSet1"
        Me.Banking_SystemDataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema
        '
        'lblinitizeAmt
        '
        Me.lblinitizeAmt.DataBindings.Add(New System.Windows.Forms.Binding("Text", Me.ChequesBindingSource, "Amount In Bank", True))
        Me.lblinitizeAmt.ForeColor = System.Drawing.Color.Black
        Me.lblinitizeAmt.Location = New System.Drawing.Point(134, 130)
        Me.lblinitizeAmt.Name = "lblinitizeAmt"
        Me.lblinitizeAmt.Size = New System.Drawing.Size(71, 13)
        Me.lblinitizeAmt.TabIndex = 14
        '
        'txtWithdrawal
        '
        Me.txtWithdrawal.DataBindings.Add(New System.Windows.Forms.Binding("Text", Me.ChequesBindingSource, "Withdrawal Amount", True))
        Me.txtWithdrawal.Location = New System.Drawing.Point(217, 164)
        Me.txtWithdrawal.Name = "txtWithdrawal"
        Me.txtWithdrawal.Size = New System.Drawing.Size(126, 20)
        Me.txtWithdrawal.TabIndex = 9
        '
        'txtDeposit
        '
        Me.txtDeposit.DataBindings.Add(New System.Windows.Forms.Binding("Text", Me.ChequesBindingSource, "Deposit Amount", True))
        Me.txtDeposit.Location = New System.Drawing.Point(217, 127)
        Me.txtDeposit.Name = "txtDeposit"
        Me.txtDeposit.Size = New System.Drawing.Size(126, 20)
        Me.txtDeposit.TabIndex = 7
        '
        'txtDate
        '
        Me.txtDate.DataBindings.Add(New System.Windows.Forms.Binding("Text", Me.ChequesBindingSource, "Date", True))
        Me.txtDate.Location = New System.Drawing.Point(217, 90)
        Me.txtDate.Name = "txtDate"
        Me.txtDate.Size = New System.Drawing.Size(126, 20)
        Me.txtDate.TabIndex = 5
        '
        'txtChequeNo
        '
        Me.txtChequeNo.DataBindings.Add(New System.Windows.Forms.Binding("Text", Me.ChequesBindingSource, "ChequeNo", True))
        Me.txtChequeNo.Location = New System.Drawing.Point(217, 50)
        Me.txtChequeNo.Name = "txtChequeNo"
        Me.txtChequeNo.Size = New System.Drawing.Size(126, 20)
        Me.txtChequeNo.TabIndex = 3
        '
        'LabelBalance
        '
        Me.LabelBalance.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.LabelBalance.DataBindings.Add(New System.Windows.Forms.Binding("Text", Me.ChequesBindingSource, "Amount In Bank", True))
        Me.LabelBalance.ForeColor = System.Drawing.Color.White
        Me.LabelBalance.Location = New System.Drawing.Point(217, 227)
        Me.LabelBalance.Name = "LabelBalance"
        Me.LabelBalance.Size = New System.Drawing.Size(129, 23)
        Me.LabelBalance.TabIndex = 13
        '
        'LabelAmt
        '
        Me.LabelAmt.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D
        Me.LabelAmt.ForeColor = System.Drawing.Color.White
        Me.LabelAmt.Location = New System.Drawing.Point(217, 192)
        Me.LabelAmt.Name = "LabelAmt"
        Me.LabelAmt.Size = New System.Drawing.Size(129, 23)
        Me.LabelAmt.TabIndex = 11
        '
        'txtAccount
        '
        Me.txtAccount.DataBindings.Add(New System.Windows.Forms.Binding("Text", Me.ChequesBindingSource, "AccountNo", True))
        Me.txtAccount.Location = New System.Drawing.Point(217, 21)
        Me.txtAccount.Name = "txtAccount"
        Me.txtAccount.Size = New System.Drawing.Size(126, 20)
        Me.txtAccount.TabIndex = 1
        '
        'Label8
        '
        Me.Label8.AutoSize = True
        Me.Label8.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label8.ForeColor = System.Drawing.Color.White
        Me.Label8.Location = New System.Drawing.Point(38, 228)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(90, 13)
        Me.Label8.TabIndex = 12
        Me.Label8.Text = "New Balance :"
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label7.ForeColor = System.Drawing.Color.White
        Me.Label7.Location = New System.Drawing.Point(38, 167)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(78, 13)
        Me.Label7.TabIndex = 8
        Me.Label7.Text = "Withdrawal :"
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label6.ForeColor = System.Drawing.Color.White
        Me.Label6.Location = New System.Drawing.Point(40, 127)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(54, 13)
        Me.Label6.TabIndex = 6
        Me.Label6.Text = "Deposit:"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label5.ForeColor = System.Drawing.Color.White
        Me.Label5.Location = New System.Drawing.Point(30, 57)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(74, 13)
        Me.Label5.TabIndex = 2
        Me.Label5.Text = "ChequeNo :"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label4.ForeColor = System.Drawing.Color.White
        Me.Label4.Location = New System.Drawing.Point(6, 93)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(136, 13)
        Me.Label4.TabIndex = 4
        Me.Label4.Text = "Date (DD/MM/YYYY) :"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label3.ForeColor = System.Drawing.Color.White
        Me.Label3.Location = New System.Drawing.Point(30, 28)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(86, 13)
        Me.Label3.TabIndex = 0
        Me.Label3.Text = "Account No  :"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 8.25!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.Label2.ForeColor = System.Drawing.Color.White
        Me.Label2.Location = New System.Drawing.Point(18, 193)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(110, 13)
        Me.Label2.TabIndex = 10
        Me.Label2.Text = "Previous Amount :"
        '
        'GroupBox2
        '
        Me.GroupBox2.Controls.Add(Me.btnWithdrawal)
        Me.GroupBox2.Controls.Add(Me.btnDeposit)
        Me.GroupBox2.Controls.Add(Me.btnSave)
        Me.GroupBox2.Controls.Add(Me.delButton)
        Me.GroupBox2.Controls.Add(Me.clearButton)
        Me.GroupBox2.Controls.Add(Me.backButton)
        Me.GroupBox2.Controls.Add(Me.btnNext)
        Me.GroupBox2.Controls.Add(Me.btnprev)
        Me.GroupBox2.ForeColor = System.Drawing.Color.White
        Me.GroupBox2.Location = New System.Drawing.Point(462, 40)
        Me.GroupBox2.Name = "GroupBox2"
        Me.GroupBox2.Size = New System.Drawing.Size(238, 259)
        Me.GroupBox2.TabIndex = 1
        Me.GroupBox2.TabStop = False
        Me.GroupBox2.Text = "Navigation Keys"
        '
        'btnWithdrawal
        '
        Me.btnWithdrawal.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.btnWithdrawal.Location = New System.Drawing.Point(129, 144)
        Me.btnWithdrawal.Name = "btnWithdrawal"
        Me.btnWithdrawal.Size = New System.Drawing.Size(83, 24)
        Me.btnWithdrawal.TabIndex = 8
        Me.btnWithdrawal.Text = "Withdrawal"
        Me.btnWithdrawal.UseVisualStyleBackColor = True
        '
        'btnDeposit
        '
        Me.btnDeposit.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.btnDeposit.Location = New System.Drawing.Point(22, 144)
        Me.btnDeposit.Name = "btnDeposit"
        Me.btnDeposit.Size = New System.Drawing.Size(83, 24)
        Me.btnDeposit.TabIndex = 7
        Me.btnDeposit.Text = "Deposit"
        Me.btnDeposit.UseVisualStyleBackColor = True
        '
        'btnSave
        '
        Me.btnSave.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.btnSave.Location = New System.Drawing.Point(22, 103)
        Me.btnSave.Name = "btnSave"
        Me.btnSave.Size = New System.Drawing.Size(83, 24)
        Me.btnSave.TabIndex = 6
        Me.btnSave.Text = "Save"
        Me.btnSave.UseVisualStyleBackColor = True
        '
        'delButton
        '
        Me.delButton.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.delButton.Location = New System.Drawing.Point(129, 103)
        Me.delButton.Name = "delButton"
        Me.delButton.Size = New System.Drawing.Size(83, 24)
        Me.delButton.TabIndex = 5
        Me.delButton.Text = "Delete"
        Me.delButton.UseVisualStyleBackColor = True
        '
        'clearButton
        '
        Me.clearButton.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.clearButton.Location = New System.Drawing.Point(129, 184)
        Me.clearButton.Name = "clearButton"
        Me.clearButton.Size = New System.Drawing.Size(83, 24)
        Me.clearButton.TabIndex = 3
        Me.clearButton.Text = "Clear"
        Me.clearButton.UseVisualStyleBackColor = True
        '
        'backButton
        '
        Me.backButton.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.backButton.Location = New System.Drawing.Point(22, 184)
        Me.backButton.Name = "backButton"
        Me.backButton.Size = New System.Drawing.Size(83, 24)
        Me.backButton.TabIndex = 4
        Me.backButton.Text = "Back"
        Me.ToolTip1.SetToolTip(Me.backButton, "Back to Menu")
        Me.backButton.UseVisualStyleBackColor = True
        '
        'btnNext
        '
        Me.btnNext.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.btnNext.Location = New System.Drawing.Point(129, 57)
        Me.btnNext.Name = "btnNext"
        Me.btnNext.Size = New System.Drawing.Size(83, 24)
        Me.btnNext.TabIndex = 1
        Me.btnNext.Text = "&>"
        Me.ToolTip1.SetToolTip(Me.btnNext, "Next")
        Me.btnNext.UseVisualStyleBackColor = True
        '
        'btnprev
        '
        Me.btnprev.ForeColor = System.Drawing.Color.FromArgb(CType(CType(0, Byte), Integer), CType(CType(0, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.btnprev.Location = New System.Drawing.Point(22, 58)
        Me.btnprev.Name = "btnprev"
        Me.btnprev.Size = New System.Drawing.Size(83, 24)
        Me.btnprev.TabIndex = 0
        Me.btnprev.Text = "&<"
        Me.ToolTip1.SetToolTip(Me.btnprev, "Previous")
        Me.btnprev.UseVisualStyleBackColor = True
        '
        'MenuStrip
        '
        Me.MenuStrip.Items.AddRange(New System.Windows.Forms.ToolStripItem() {Me.SaveToolStripMenuItem, Me.ExitToolStripMenuItem1})
        Me.MenuStrip.Location = New System.Drawing.Point(0, 0)
        Me.MenuStrip.Name = "MenuStrip"
        Me.MenuStrip.Size = New System.Drawing.Size(712, 24)
        Me.MenuStrip.TabIndex = 2
        Me.MenuStrip.Text = "MenuStrip"
        '
        'SaveToolStripMenuItem
        '
        Me.SaveToolStripMenuItem.DropDownItems.AddRange(New System.Windows.Forms.ToolStripItem() {Me.SaveToolStripMenuItem1, Me.LogoutToolStripMenuItem})
        Me.SaveToolStripMenuItem.Name = "SaveToolStripMenuItem"
        Me.SaveToolStripMenuItem.Size = New System.Drawing.Size(35, 20)
        Me.SaveToolStripMenuItem.Text = "File"
        '
        'SaveToolStripMenuItem1
        '
        Me.SaveToolStripMenuItem1.Name = "SaveToolStripMenuItem1"
        Me.SaveToolStripMenuItem1.ShortcutKeys = CType((System.Windows.Forms.Keys.Control Or System.Windows.Forms.Keys.S), System.Windows.Forms.Keys)
        Me.SaveToolStripMenuItem1.Size = New System.Drawing.Size(139, 22)
        Me.SaveToolStripMenuItem1.Text = "Save "
        '
        'LogoutToolStripMenuItem
        '
        Me.LogoutToolStripMenuItem.Name = "LogoutToolStripMenuItem"
        Me.LogoutToolStripMenuItem.Size = New System.Drawing.Size(139, 22)
        Me.LogoutToolStripMenuItem.Text = "Logout"
        '
        'ExitToolStripMenuItem1
        '
        Me.ExitToolStripMenuItem1.Name = "ExitToolStripMenuItem1"
        Me.ExitToolStripMenuItem1.Size = New System.Drawing.Size(37, 20)
        Me.ExitToolStripMenuItem1.Text = "Exit"
        '
        'DataGridView1
        '
        Me.DataGridView1.AutoGenerateColumns = False
        Me.DataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize
        Me.DataGridView1.Columns.AddRange(New System.Windows.Forms.DataGridViewColumn() {Me.DateDataGridViewTextBoxColumn, Me.ChequeNoDataGridViewTextBoxColumn, Me.DepositAmountDataGridViewTextBoxColumn, Me.WithdrawalAmountDataGridViewTextBoxColumn, Me.AccountNoDataGridViewTextBoxColumn, Me.AmountInBankDataGridViewTextBoxColumn})
        Me.DataGridView1.DataSource = Me.ChequesBindingSource
        Me.DataGridView1.Location = New System.Drawing.Point(37, 320)
        Me.DataGridView1.Name = "DataGridView1"
        Me.DataGridView1.Size = New System.Drawing.Size(663, 150)
        Me.DataGridView1.TabIndex = 3
        '
        'DateDataGridViewTextBoxColumn
        '
        Me.DateDataGridViewTextBoxColumn.DataPropertyName = "Date"
        Me.DateDataGridViewTextBoxColumn.HeaderText = "Date"
        Me.DateDataGridViewTextBoxColumn.Name = "DateDataGridViewTextBoxColumn"
        '
        'ChequeNoDataGridViewTextBoxColumn
        '
        Me.ChequeNoDataGridViewTextBoxColumn.DataPropertyName = "ChequeNo"
        Me.ChequeNoDataGridViewTextBoxColumn.HeaderText = "ChequeNo"
        Me.ChequeNoDataGridViewTextBoxColumn.Name = "ChequeNoDataGridViewTextBoxColumn"
        '
        'DepositAmountDataGridViewTextBoxColumn
        '
        Me.DepositAmountDataGridViewTextBoxColumn.DataPropertyName = "Deposit Amount"
        Me.DepositAmountDataGridViewTextBoxColumn.HeaderText = "Deposit Amount"
        Me.DepositAmountDataGridViewTextBoxColumn.Name = "DepositAmountDataGridViewTextBoxColumn"
        '
        'WithdrawalAmountDataGridViewTextBoxColumn
        '
        Me.WithdrawalAmountDataGridViewTextBoxColumn.DataPropertyName = "Withdrawal Amount"
        Me.WithdrawalAmountDataGridViewTextBoxColumn.HeaderText = "Withdrawal Amount"
        Me.WithdrawalAmountDataGridViewTextBoxColumn.Name = "WithdrawalAmountDataGridViewTextBoxColumn"
        '
        'AccountNoDataGridViewTextBoxColumn
        '
        Me.AccountNoDataGridViewTextBoxColumn.DataPropertyName = "AccountNo"
        Me.AccountNoDataGridViewTextBoxColumn.HeaderText = "AccountNo"
        Me.AccountNoDataGridViewTextBoxColumn.Name = "AccountNoDataGridViewTextBoxColumn"
        '
        'AmountInBankDataGridViewTextBoxColumn
        '
        Me.AmountInBankDataGridViewTextBoxColumn.DataPropertyName = "Amount In Bank"
        Me.AmountInBankDataGridViewTextBoxColumn.HeaderText = "Amount In Bank"
        Me.AmountInBankDataGridViewTextBoxColumn.Name = "AmountInBankDataGridViewTextBoxColumn"
        '
        'ChequesTableAdapter
        '
        Me.ChequesTableAdapter.ClearBeforeFill = True
        '
        'chequesForm
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.BackColor = System.Drawing.Color.Black
        Me.ClientSize = New System.Drawing.Size(712, 606)
        Me.Controls.Add(Me.DataGridView1)
        Me.Controls.Add(Me.GroupBox2)
        Me.Controls.Add(Me.GroupBox1)
        Me.Controls.Add(Me.MenuStrip)
        Me.MainMenuStrip = Me.MenuStrip
        Me.Name = "chequesForm"
        Me.Text = "Cheques"
        Me.GroupBox1.ResumeLayout(False)
        Me.GroupBox1.PerformLayout()
        CType(Me.ChequesBindingSource, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.Banking_SystemDataSet1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.GroupBox2.ResumeLayout(False)
        Me.MenuStrip.ResumeLayout(False)
        Me.MenuStrip.PerformLayout()
        CType(Me.DataGridView1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents GroupBox1 As System.Windows.Forms.GroupBox
    Friend WithEvents Label8 As System.Windows.Forms.Label
    Friend WithEvents Label7 As System.Windows.Forms.Label
    Friend WithEvents Label6 As System.Windows.Forms.Label
    Friend WithEvents Label5 As System.Windows.Forms.Label
    Friend WithEvents Label4 As System.Windows.Forms.Label
    Friend WithEvents Label3 As System.Windows.Forms.Label
    Friend WithEvents Label2 As System.Windows.Forms.Label
    Friend WithEvents GroupBox2 As System.Windows.Forms.GroupBox
    Friend WithEvents LabelBalance As System.Windows.Forms.Label
    Friend WithEvents LabelAmt As System.Windows.Forms.Label
    Friend WithEvents txtAccount As System.Windows.Forms.TextBox
    Friend WithEvents txtChequeNo As System.Windows.Forms.TextBox
    Friend WithEvents txtWithdrawal As System.Windows.Forms.TextBox
    Friend WithEvents txtDeposit As System.Windows.Forms.TextBox
    Friend WithEvents txtDate As System.Windows.Forms.TextBox
    Friend WithEvents backButton As System.Windows.Forms.Button
    Friend WithEvents btnNext As System.Windows.Forms.Button
    Friend WithEvents btnprev As System.Windows.Forms.Button
    Friend WithEvents clearButton As System.Windows.Forms.Button
    Friend WithEvents MenuStrip As System.Windows.Forms.MenuStrip
    Friend WithEvents SaveToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents SaveToolStripMenuItem1 As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents LogoutToolStripMenuItem As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents ExitToolStripMenuItem1 As System.Windows.Forms.ToolStripMenuItem
    Friend WithEvents ToolTip1 As System.Windows.Forms.ToolTip
    Friend WithEvents delButton As System.Windows.Forms.Button
    Friend WithEvents btnSave As System.Windows.Forms.Button
    Friend WithEvents btnWithdrawal As System.Windows.Forms.Button
    Friend WithEvents btnDeposit As System.Windows.Forms.Button
    Friend WithEvents lblinitizeAmt As System.Windows.Forms.Label
    Friend WithEvents lblfirstAmt As System.Windows.Forms.Label
    Friend WithEvents DataGridView1 As System.Windows.Forms.DataGridView
    Friend WithEvents Banking_SystemDataSet1 As Cheques_and_Deposits_Project.Banking_SystemDataSet1
    Friend WithEvents ChequesBindingSource As System.Windows.Forms.BindingSource
    Friend WithEvents ChequesTableAdapter As Cheques_and_Deposits_Project.Banking_SystemDataSet1TableAdapters.ChequesTableAdapter
    Friend WithEvents DateDataGridViewTextBoxColumn As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents ChequeNoDataGridViewTextBoxColumn As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents DepositAmountDataGridViewTextBoxColumn As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents WithdrawalAmountDataGridViewTextBoxColumn As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents AccountNoDataGridViewTextBoxColumn As System.Windows.Forms.DataGridViewTextBoxColumn
    Friend WithEvents AmountInBankDataGridViewTextBoxColumn As System.Windows.Forms.DataGridViewTextBoxColumn
End Class
