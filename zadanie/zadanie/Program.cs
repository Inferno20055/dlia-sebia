using System;
//zadanie 1
/*class Program
{
    static void Main()
    {
        Console.Write("Введите значение A (длина прямоугольника): ");
        int A = int.Parse(Console.ReadLine());

        Console.Write("Введите значение B (ширина прямоугольника): ");
        int B = int.Parse(Console.ReadLine());

        Console.Write("Введите значение C (сторона квадрата): ");
        int C = int.Parse(Console.ReadLine());

        if (C > A || C > B)
        {
            Console.WriteLine("Невозможно разместить ни одного квадрата со стороной C в прямоугольнике.");
            return;
        }

        int squaresInLength = A / C; 
        int squaresInWidth = B / C;   
        int totalSquares = squaresInLength * squaresInWidth; 

        int areaOfRectangle = A * B; 
        int areaOfSquares = totalSquares * (C * C); 
        int unoccupiedArea = areaOfRectangle - areaOfSquares; 

        Console.WriteLine($"Количество квадратов, размещенных на прямоугольнике: {totalSquares}");
        Console.WriteLine($"Площадь незанятой части прямоугольника: {unoccupiedArea}");
    }
}*/
//zadanie 2
/*class Program {
    static void Main() {
        int oklad = 10000;
        int TargetAmount = 11000;
        int month=0;
        int CurrentAmount = oklad;
        Console.Write("Введите процент P(0<P<25):" );
        int P =int.Parse( Console.ReadLine());
        if (P<=0||P>=25)
        {
            Console.Write("Ошибка: значение Р должно быть в диапозоне(0,25).");
            return;
        }
        while (CurrentAmount <= TargetAmount)
        {
            CurrentAmount += CurrentAmount * (P / 100);
            month++;
        }
        Console.WriteLine($"Количество месяцев K: {month}");
        Console.WriteLine($"Итоговый размер вклада S: {CurrentAmount:F2} руб.");
    }
}*/
//zadanie 3
/*class Program
{
    static void Main() {
        Console.Write("Введите целое положительное число A (A < B): ");
        int A = int.Parse(Console.ReadLine());

        Console.Write("Введите целое положительное число B (B > A): ");
        int B = int.Parse(Console.ReadLine());

        // Проверка условия A < B
        if (A <= 0 || B <= 0 || A >= B)
        {
            Console.WriteLine("Ошибка: Убедитесь, что A и B положительные числа и A < B.");
            return;
        }

        // Вывод чисел от A до B
        for (int i = A; i <= B; i++)
        {
            for (int j = 0; j < i; j++)
            {
                Console.Write(i + " ");
            }
            Console.WriteLine(); 
        }
    }
}*/
//zadnie 4
class Program
{
    static void Main()
    {
        Console.Write("Введите целое положительное число N: ");
        int N = int.Parse(Console.ReadLine());

        if (N <= 0)
        {
            Console.WriteLine("Ошибка: число должно быть больше 0.");
            return;
        }

        int reversedNumber = 0;

        while (N > 0)
        {
            int digit = N % 10; 
            reversedNumber = reversedNumber * 10 + digit; 
            N /= 10; 
        }
        Console.WriteLine($"Число, прочитанное справа налево: {reversedNumber}");
    }
}
