using System.Linq.Expressions;
using System.Runtime.CompilerServices;
using System.Collections.Generic;
using Internal;
using System;

namespace HiddenPassword
{
    class Program
    {
        static void Main()
        {
            //int t = 0, n = 0, pos = 0;
            string s = "ala";
            //List<string> box = new List<string>();
            //t = Convert.ToInt32(Console.ReadLine());
            //t++;
            //n++;
            //pos++;
			Console.WriteLine(ConvToBin(s[0]));
            /*for (int i = 0; i < t; i++)
            {
                n = Convert.toInt32(Console.ReadLine());
                s = Console.ReadLine();
                pos = s.indexOf(" ");
                for (int j = 0; j < n; j++)
                {
                    box.Add(s.Substring());
                }
                foreach (string a in box)
                {
                    foreach (char c in a)
                    {

                    }
                }
            }*/
        }

        public static string ConvToBin(char c)
        {
            int temp = 0, pos = 0;
            string s = "00000000";
            temp = c;
            char[]change = s.ToCharArray();
            /*while (temp != 0)
            {
                while (Math.Pow(2, pos) < temp)
                {
                    pos++;
                }
            }*/

            while(temp > 1)
            {
                if (temp%2==1)
                {
                    change[pos] = '1';
                    pos++;
                    temp/=2;
                }
                else
                {
                    pos++;
                    temp/=2;
                }
            }
			s = new string(change);

            return s;
        }
    }
}