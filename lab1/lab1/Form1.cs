/*
 Шевчук П.В. М80-304Б-16 
 Вариант № 15
 Построение кривой p=(a*cos(2phi))/cos(phi), 
 С условием -pi < A <= x <= B < pi
*/

using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
//j

namespace lab1
{
    public partial class Form1 : Form
    {
        // Глобальные переменные
        float scale = 1; // масштаб
        Point zero; // центр
        bool drawcurve = false;
        Graphics g;
        bool mousePress = false;
        Point mousePressPoint; // начальное положение

        // Центр
        private Point CalcCentr()
        {
            return new Point(drawBox.Width / 2, drawBox.Height / 2);
        }

        // Конструктор
        public Form1()
        {
            InitializeComponent();
            zero = CalcCentr();
            drawBox.MouseWheel += DrawBox_MouseWheel;
        }

        // Моя функция
        private double myFunc(double a, double t)
        {
            return a * Math.Cos(2 * t) / Math.Cos(t);
        }

        // Построить оконо с графиком по функциям
        private void drawBox_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;
            g.ScaleTransform(scale, scale);
            g.TranslateTransform(zero.X + offset.X, zero.Y + offset.Y);
            DrawCoordinates(g, Pens.Red);
            if (drawcurve) DrawCurve(g);
        }
        int MAX = 1000000;

        // Посторить кривую
        private void DrawCurve(Graphics g)
        {
            Pen linePen = new Pen(Color.Blue, 1);
            double aBorder;
            double bBorder;
            double paramA;
            double step;

            try
            {
                aBorder = Convert.ToDouble(textBox1.Text); // A
                bBorder = Convert.ToDouble(textBox2.Text); // B
                paramA = Convert.ToDouble(textBox3.Text); // a
                step = 100; // approax

            }
            catch (Exception)
            {
                MessageBox.Show("Неверный формат ввода параметров");
                return;
            }

            step /= 1000;

            var points = new List<PointF>();

            for (double i = aBorder; i < bBorder; i += step)
            {
                var r = myFunc(paramA, i); // Моя функция
                PointF begin = ToDecart(r, i);
                points.Add(begin);
            }

            if (points.Count < 2)
            {
                MessageBox.Show("Задан слишком большой шаг");
                return;
            }

            var ARR = points.ToArray();
            var last = ARR[0];
            for (int i = 1; i < ARR.Length; i++)
            {
                if (ARR[i].Y - last.Y > 10000 * step)
                {
                    last = ARR[i];
                    continue;
                }

                g.DrawLine(linePen, last, ARR[i]);
                last = ARR[i];
            }
            g.DrawString("p=(a*cos(2phi))/cos(phi)", new Font("ARIAL", 12), Brushes.Black, new PointF(38, -38));

        }
        Point offset;
        Point oldoffset;

        // В декартовых координатах
        private PointF ToDecart(double r, double d)
        {
            float x = (float)(r * Math.Cos(d));
            if (Math.Abs(x) < 0.001) x = 0;
            if (Math.Abs(x) > 100000) x = 100000;

            float y = (float)(r * Math.Sin(d));
            if (Math.Abs(y) < 0.001) y = 0;
            if (Math.Abs(y) > 1000)
            {
                if (y >= 0)
                    y = 1000;
                else
                    y = -1000;
            }

            return new PointF(x, y);
        }

        // Построение осей
        private void DrawCoordinates(Graphics g, Pen p)
        {

            Pen grid_pen = new Pen(Color.Silver, 0.0001f);
            for (int i = -1000; i < 1000; i += 10)
            {
                for (int j = -1000; j < 1000; j += 10)
                {
                    g.DrawLine(grid_pen, new Point(i, -j), new Point(i, j));
                    g.DrawLine(grid_pen, new Point(-i, j), new Point(i, j));

                    if (i % 100 == 0)
                    {
                        g.DrawString((i / 10).ToString(), DefaultFont, Brushes.Green, new Point(i, 10));
                        if (i != 0)
                        {
                            g.DrawString((i / 10).ToString(), DefaultFont, Brushes.Green, new Point(10, -i));
                        }

                    }
                    g.DrawLine(p, new Point(-i, i), new Point(i, i));
                }

            }
            g.DrawLine(p, new Point(-MAX, 0), new Point(MAX, 0));
            g.DrawLine(p, new Point(0, -MAX), new Point(0, MAX));

        }

        
        void pictureBox1_Paint(object sender, PaintEventArgs e)
        {
            ControlPaint.DrawGrid(e.Graphics, e.ClipRectangle, new Size(10, 10), Color.White);
        }

        // Масштабирование
        private void DrawBox_MouseWheel(object sender, MouseEventArgs e)
        {
            if (e.Delta > 0)
                scale *= 1.1f;
            else
            {
                scale *= 0.9f;
            }

            drawBox.Invalidate();
        }

        // Прокрутка вверх
        private void drawBox_MouseDown(object sender, MouseEventArgs e)
        {
            mousePress = true;
            mousePressPoint = e.Location;
            oldoffset = new Point(offset.X, offset.Y);

        }

        // Прокрутка вниз
        private void drawBox_MouseUp(object sender, MouseEventArgs e)
        {
            mousePress = false;
            //mousePressPoint = new Point();
        }

        // Просмотр графика
        private void drawBox_MouseMove(object sender, MouseEventArgs e)
        {
            if (mousePress)
            {
                int dx = e.X - mousePressPoint.X;
                int dy = e.Y - mousePressPoint.Y;

                offset = new Point(oldoffset.X + (int)(dx / scale), oldoffset.Y + (int)(dy / scale));
                drawBox.Invalidate();
            }
        }

        private void drawBox_SizeChanged(object sender, EventArgs e)
        {
            zero = CalcCentr();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            scale = 1;
            drawcurve = !drawcurve;
            offset = new Point();

            drawBox.Invalidate();

        }

        private void textBox1_TextChanged_1(object sender, EventArgs e)
        {
            drawcurve = false;
            drawBox.Invalidate();
        }

        private void panel1_Paint(object sender, PaintEventArgs e){}
        private void drawBox_Click(object sender, EventArgs e){}
        private void button2_Click(object sender, EventArgs e){}
        private void label1_Click(object sender, EventArgs e){}
    }
}
