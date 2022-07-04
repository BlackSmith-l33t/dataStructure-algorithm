using System;
using System.Collections.Generic;

namespace Shuffle
{
    class Shuffle
    {
        public static Random rng = new Random();

        static void Main(string[] args)
        {

            List<int> list = new List<int>() { 1, 2, 3, 4, 5, 6, 7, 8 };

            Shuffle_List(list);

            foreach (var item in list)
            {
                Console.Write(item);
                Console.Write(" ");
            }
        }

        public static void Shuffle_List<T>(List<T> list)
        {
            int n = list.Count;
            while (n > 1)
            {
                n--;
                int k = rng.Next(n + 1);
                T value = list[k];
                list[k] = list[n];
                list[n] = value;
            }
        }
    }
}
    
