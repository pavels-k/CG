namespace lab3CG
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.mashtabPanel = new System.Windows.Forms.Panel();
            this.mashtabLabel = new System.Windows.Forms.Label();
            this.mashtabPlusButton = new System.Windows.Forms.Button();
            this.mashtabMinusButton = new System.Windows.Forms.Button();
            this.panelOfApproximation = new System.Windows.Forms.Panel();
            this.textBoxOfNumberOfParabols = new System.Windows.Forms.TextBox();
            this.labelOfNumberOfParabols = new System.Windows.Forms.Label();
            this.labelOfNumberOfCircles = new System.Windows.Forms.Label();
            this.textBoxOfNumberOfCircles = new System.Windows.Forms.TextBox();
            this.buttonOfApply1 = new System.Windows.Forms.Button();
            this.panelOfLight = new System.Windows.Forms.Panel();
            this.trackBarMir = new System.Windows.Forms.TrackBar();
            this.trackBarRas = new System.Windows.Forms.TrackBar();
            this.trackBarFon = new System.Windows.Forms.TrackBar();
            this.label4 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.buttonOfColor = new System.Windows.Forms.Button();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.checkBoxOfIlluminate = new System.Windows.Forms.CheckBox();
            this.mashtabPanel.SuspendLayout();
            this.panelOfApproximation.SuspendLayout();
            this.panelOfLight.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarMir)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarRas)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarFon)).BeginInit();
            this.SuspendLayout();
            // 
            // mashtabPanel
            // 
            this.mashtabPanel.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.mashtabPanel.Controls.Add(this.mashtabLabel);
            this.mashtabPanel.Controls.Add(this.mashtabPlusButton);
            this.mashtabPanel.Controls.Add(this.mashtabMinusButton);
            this.mashtabPanel.Location = new System.Drawing.Point(45, 23);
            this.mashtabPanel.Name = "mashtabPanel";
            this.mashtabPanel.Size = new System.Drawing.Size(142, 33);
            this.mashtabPanel.TabIndex = 22;
            // 
            // mashtabLabel
            // 
            this.mashtabLabel.AutoSize = true;
            this.mashtabLabel.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.mashtabLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.mashtabLabel.Location = new System.Drawing.Point(3, 8);
            this.mashtabLabel.Name = "mashtabLabel";
            this.mashtabLabel.Size = new System.Drawing.Size(68, 15);
            this.mashtabLabel.TabIndex = 18;
            this.mashtabLabel.Text = "Масштаб";
            // 
            // mashtabPlusButton
            // 
            this.mashtabPlusButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.mashtabPlusButton.Location = new System.Drawing.Point(110, 5);
            this.mashtabPlusButton.Name = "mashtabPlusButton";
            this.mashtabPlusButton.Size = new System.Drawing.Size(27, 23);
            this.mashtabPlusButton.TabIndex = 19;
            this.mashtabPlusButton.Text = "+";
            this.mashtabPlusButton.UseVisualStyleBackColor = true;
            this.mashtabPlusButton.Click += new System.EventHandler(this.mashtabPlusButton_Click);
            // 
            // mashtabMinusButton
            // 
            this.mashtabMinusButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.mashtabMinusButton.Location = new System.Drawing.Point(77, 5);
            this.mashtabMinusButton.Name = "mashtabMinusButton";
            this.mashtabMinusButton.Size = new System.Drawing.Size(27, 23);
            this.mashtabMinusButton.TabIndex = 20;
            this.mashtabMinusButton.Text = "-";
            this.mashtabMinusButton.UseVisualStyleBackColor = true;
            this.mashtabMinusButton.Click += new System.EventHandler(this.mashtabMinusButton_Click);
            // 
            // panelOfApproximation
            // 
            this.panelOfApproximation.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelOfApproximation.Controls.Add(this.textBoxOfNumberOfParabols);
            this.panelOfApproximation.Controls.Add(this.labelOfNumberOfParabols);
            this.panelOfApproximation.Controls.Add(this.labelOfNumberOfCircles);
            this.panelOfApproximation.Controls.Add(this.textBoxOfNumberOfCircles);
            this.panelOfApproximation.Controls.Add(this.buttonOfApply1);
            this.panelOfApproximation.Location = new System.Drawing.Point(45, 384);
            this.panelOfApproximation.Name = "panelOfApproximation";
            this.panelOfApproximation.Size = new System.Drawing.Size(142, 119);
            this.panelOfApproximation.TabIndex = 23;
            // 
            // textBoxOfNumberOfParabols
            // 
            this.textBoxOfNumberOfParabols.Location = new System.Drawing.Point(20, 60);
            this.textBoxOfNumberOfParabols.Name = "textBoxOfNumberOfParabols";
            this.textBoxOfNumberOfParabols.Size = new System.Drawing.Size(100, 20);
            this.textBoxOfNumberOfParabols.TabIndex = 2;
            this.textBoxOfNumberOfParabols.Text = "10";
            this.textBoxOfNumberOfParabols.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // labelOfNumberOfParabols
            // 
            this.labelOfNumberOfParabols.AutoSize = true;
            this.labelOfNumberOfParabols.Location = new System.Drawing.Point(17, 44);
            this.labelOfNumberOfParabols.Name = "labelOfNumberOfParabols";
            this.labelOfNumberOfParabols.Size = new System.Drawing.Size(117, 13);
            this.labelOfNumberOfParabols.TabIndex = 8;
            this.labelOfNumberOfParabols.Text = "Количество парабол  ";
            // 
            // labelOfNumberOfCircles
            // 
            this.labelOfNumberOfCircles.AutoSize = true;
            this.labelOfNumberOfCircles.Location = new System.Drawing.Point(6, 0);
            this.labelOfNumberOfCircles.Name = "labelOfNumberOfCircles";
            this.labelOfNumberOfCircles.Size = new System.Drawing.Size(135, 13);
            this.labelOfNumberOfCircles.TabIndex = 5;
            this.labelOfNumberOfCircles.Text = "Количество окружностей";
            // 
            // textBoxOfNumberOfCircles
            // 
            this.textBoxOfNumberOfCircles.Location = new System.Drawing.Point(20, 21);
            this.textBoxOfNumberOfCircles.Name = "textBoxOfNumberOfCircles";
            this.textBoxOfNumberOfCircles.Size = new System.Drawing.Size(100, 20);
            this.textBoxOfNumberOfCircles.TabIndex = 6;
            this.textBoxOfNumberOfCircles.Text = "10";
            this.textBoxOfNumberOfCircles.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // buttonOfApply1
            // 
            this.buttonOfApply1.Location = new System.Drawing.Point(20, 86);
            this.buttonOfApply1.Name = "buttonOfApply1";
            this.buttonOfApply1.Size = new System.Drawing.Size(100, 23);
            this.buttonOfApply1.TabIndex = 7;
            this.buttonOfApply1.Text = "Применить";
            this.buttonOfApply1.UseVisualStyleBackColor = true;
            this.buttonOfApply1.Click += new System.EventHandler(this.buttonOfApply1_Click);
            // 
            // panelOfLight
            // 
            this.panelOfLight.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelOfLight.Controls.Add(this.trackBarMir);
            this.panelOfLight.Controls.Add(this.trackBarRas);
            this.panelOfLight.Controls.Add(this.trackBarFon);
            this.panelOfLight.Controls.Add(this.label4);
            this.panelOfLight.Controls.Add(this.label2);
            this.panelOfLight.Controls.Add(this.label1);
            this.panelOfLight.Controls.Add(this.label3);
            this.panelOfLight.Controls.Add(this.buttonOfColor);
            this.panelOfLight.Enabled = false;
            this.panelOfLight.Location = new System.Drawing.Point(45, 120);
            this.panelOfLight.Name = "panelOfLight";
            this.panelOfLight.Size = new System.Drawing.Size(171, 238);
            this.panelOfLight.TabIndex = 25;
            // 
            // trackBarMir
            // 
            this.trackBarMir.Location = new System.Drawing.Point(35, 199);
            this.trackBarMir.Maximum = 5;
            this.trackBarMir.Name = "trackBarMir";
            this.trackBarMir.Size = new System.Drawing.Size(104, 45);
            this.trackBarMir.TabIndex = 25;
            this.trackBarMir.ValueChanged += new System.EventHandler(this.trackBarMir_ValueChanged);
            // 
            // trackBarRas
            // 
            this.trackBarRas.Location = new System.Drawing.Point(35, 133);
            this.trackBarRas.Maximum = 5;
            this.trackBarRas.Name = "trackBarRas";
            this.trackBarRas.Size = new System.Drawing.Size(104, 45);
            this.trackBarRas.TabIndex = 24;
            this.trackBarRas.Value = 5;
            this.trackBarRas.ValueChanged += new System.EventHandler(this.trackBarRas_ValueChanged);
            // 
            // trackBarFon
            // 
            this.trackBarFon.Location = new System.Drawing.Point(33, 67);
            this.trackBarFon.Maximum = 5;
            this.trackBarFon.Name = "trackBarFon";
            this.trackBarFon.Size = new System.Drawing.Size(104, 45);
            this.trackBarFon.TabIndex = 23;
            this.trackBarFon.ValueChanged += new System.EventHandler(this.trackBarFon_ValueChanged);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label4.Location = new System.Drawing.Point(64, 5);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(41, 15);
            this.label4.TabIndex = 22;
            this.label4.Text = "Цвет";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(2, 181);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(164, 15);
            this.label2.TabIndex = 20;
            this.label2.Text = "Зеркальное освещение";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.label1.Location = new System.Drawing.Point(17, 49);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(144, 15);
            this.label1.TabIndex = 19;
            this.label1.Text = "Фоновое освещение";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.BackColor = System.Drawing.SystemColors.ControlLightLight;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(3, 115);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(163, 15);
            this.label3.TabIndex = 21;
            this.label3.Text = "Рассеянное освещение";
            // 
            // buttonOfColor
            // 
            this.buttonOfColor.BackColor = System.Drawing.Color.LightSeaGreen;
            this.buttonOfColor.Location = new System.Drawing.Point(47, 23);
            this.buttonOfColor.Name = "buttonOfColor";
            this.buttonOfColor.Size = new System.Drawing.Size(75, 23);
            this.buttonOfColor.TabIndex = 0;
            this.buttonOfColor.UseVisualStyleBackColor = false;
            this.buttonOfColor.Click += new System.EventHandler(this.buttonOfColor_Click);
            // 
            // checkBoxOfIlluminate
            // 
            this.checkBoxOfIlluminate.AutoSize = true;
            this.checkBoxOfIlluminate.Location = new System.Drawing.Point(45, 86);
            this.checkBoxOfIlluminate.Name = "checkBoxOfIlluminate";
            this.checkBoxOfIlluminate.Size = new System.Drawing.Size(134, 17);
            this.checkBoxOfIlluminate.TabIndex = 27;
            this.checkBoxOfIlluminate.Text = "включить освещение";
            this.checkBoxOfIlluminate.UseVisualStyleBackColor = true;
            this.checkBoxOfIlluminate.CheckedChanged += new System.EventHandler(this.checkBoxOfIlluminate_CheckedChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.ButtonHighlight;
            this.ClientSize = new System.Drawing.Size(878, 602);
            this.Controls.Add(this.checkBoxOfIlluminate);
            this.Controls.Add(this.panelOfLight);
            this.Controls.Add(this.panelOfApproximation);
            this.Controls.Add(this.mashtabPanel);
            this.DoubleBuffered = true;
            this.Name = "Form1";
            this.Text = "Лабораторная работа №3 Шевчук П.В.";
            this.SizeChanged += new System.EventHandler(this.Form1_SizeChanged);
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseMove);
            this.MouseUp += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseUp);
            this.mashtabPanel.ResumeLayout(false);
            this.mashtabPanel.PerformLayout();
            this.panelOfApproximation.ResumeLayout(false);
            this.panelOfApproximation.PerformLayout();
            this.panelOfLight.ResumeLayout(false);
            this.panelOfLight.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarMir)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarRas)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trackBarFon)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel mashtabPanel;
        private System.Windows.Forms.Label mashtabLabel;
        private System.Windows.Forms.Button mashtabPlusButton;
        private System.Windows.Forms.Button mashtabMinusButton;
        private System.Windows.Forms.Panel panelOfApproximation;
        private System.Windows.Forms.TextBox textBoxOfNumberOfCircles;
        private System.Windows.Forms.Button buttonOfApply1;
        private System.Windows.Forms.Label labelOfNumberOfCircles;
        private System.Windows.Forms.TextBox textBoxOfNumberOfParabols;
        private System.Windows.Forms.Label labelOfNumberOfParabols;
        private System.Windows.Forms.Panel panelOfLight;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.Button buttonOfColor;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TrackBar trackBarMir;
        private System.Windows.Forms.TrackBar trackBarRas;
        private System.Windows.Forms.TrackBar trackBarFon;
        private System.Windows.Forms.CheckBox checkBoxOfIlluminate;
    }
}