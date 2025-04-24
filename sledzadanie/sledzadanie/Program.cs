//zadanie 1
using System;

/*class Program
{
    static void Main()
    {
        Console.Write("Введите число от 1 до 100: ");
        int number;

        if (!int.TryParse(Console.ReadLine(), out number))
        {
            Console.WriteLine("Ошибка: введено не число.");
            return;
        }

        if (number < 1 || number > 100)
        {
            Console.WriteLine("Ошибка: число должно быть в диапазоне от 1 до 100.");
            return;
        }

        if (number % 3 == 0 && number % 5 == 0)
        {
            Console.WriteLine("Fizz Buzz");
        }
        else if (number % 3 == 0)
        {
            Console.WriteLine("Fizz");
        }
        else if (number % 5 == 0)
        {
            Console.WriteLine("Buzz");
        }
        else
        {
            Console.WriteLine(number);
        }
    }
}*/
//zadanie 2
/*class Program
{
    static void Main()
    {
        Console.Write("Введите значение: ");
        double value;

        if (!double.TryParse(Console.ReadLine(), out value))
        {
            Console.WriteLine("Ошибка: введено не число.");
            return;
        }

        Console.Write("Введите процент: ");
        double percentage;

        if (!double.TryParse(Console.ReadLine(), out percentage))
        {
            Console.WriteLine("Ошибка: введено не число.");
            return;
        }

        double result = (value * percentage) / 100;

        Console.WriteLine($"{percentage} процентов от {value} равно {result}");
    }
}*/
//zadanie 3
/*class Program
{
    static void Main()
    {
        int[] digits = new int[4];

        for (int i = 0; i < 4; i++)
        {
            Console.Write($"Введите цифру {i + 1}: ");
            if (!int.TryParse(Console.ReadLine(), out digits[i]) || digits[i] < 0 || digits[i] > 9)
            {
                Console.WriteLine("Ошибка: введено не число или не цифра (0-9).");
                return;
            }
        }

        string result = string.Join("", digits);

        Console.WriteLine($"Сформированное число: {result}");
    }
}*/
//zadanie 5
/*class Program
{
    static void Main()
    {
        Console.Write("Введите дату в формате ДД.ММ.ГГГГ: ");
        string input = Console.ReadLine();

        if (!DateTime.TryParse(input, out DateTime date))
        {
            Console.WriteLine("Ошибка: введена некорректная дата.");
            return;
        }

        string season = GetSeason(date);

        string dayOfWeek = date.DayOfWeek.ToString();

        Console.WriteLine($"{season} {dayOfWeek}");
    }

    static string GetSeason(DateTime date)
    {
        if (date.Month == 12 || date.Month == 1 || date.Month == 2)
            return "Winter";
        else if (date.Month >= 3 && date.Month <= 5)
            return "Spring";
        else if (date.Month >= 6 && date.Month <= 8)
            return "Summer";
        else
            return "Autumn";
    }
}*/
//zadanie 4
/*class Program
{
    static void Main()
    {
        Console.Write("Введите шестизначное число: ");
        string input = Console.ReadLine();

        if (input.Length != 6 || !int.TryParse(input, out _))
        {
            Console.WriteLine("Ошибка: введено не шестизначное число.");
            return;
        }

        Console.Write("Введите номера разрядов для обмена (например, 1 и 6): ");
        string[] positions = Console.ReadLine().Split(' ');

        if (positions.Length != 2 ||
            !int.TryParse(positions[0], out int pos1) ||
            !int.TryParse(positions[1], out int pos2) ||
            pos1 < 1 || pos1 > 6 ||
            pos2 < 1 || pos2 > 6)
        {
            Console.WriteLine("Ошибка: некорректные номера разрядов.");
            return;
        }

        char[] digits = input.ToCharArray();

        char temp = digits[pos1 - 1];
        digits[pos1 - 1] = digits[pos2 - 1];
        digits[pos2 - 1] = temp;

        string result = new string(digits);

        Console.WriteLine($"Результат: {result}");
    }
}*/
//zadanie 6
/*class Program
{
    static void Main()
    {
        Console.WriteLine("Выберите перевод температуры:");
        Console.WriteLine("1 - Фаренгейт в Цельсий");
        Console.WriteLine("2 - Цельсий в Фаренгейт");

        // Ввод выбора пользователя
        Console.Write("Введите номер выбора (1 или 2): ");
        string choice = Console.ReadLine();

        double temperature;

        if (choice == "1")
        {
            // Перевод из Фаренгейта в Цельсий
            Console.Write("Введите температуру в Фаренгейтах: ");
            if (double.TryParse(Console.ReadLine(), out temperature))
            {
                double celsius = (temperature - 32) * 5 / 9;
                Console.WriteLine($"Температура в Цельсии: {celsius:F2} °C");
            }
            else
            {
                Console.WriteLine("Ошибка: введено некорректное значение температуры.");
            }
        }
        else if (choice == "2")
        {
            // Перевод из Цельсия в Фаренгейт
            Console.Write("Введите температуру в Цельсиях: ");
            if (double.TryParse(Console.ReadLine(), out temperature))
            {
                double fahrenheit = (temperature * 9 / 5) + 32;
                Console.WriteLine($"Температура в Фаренгейтах: {fahrenheit:F2} °F");
            }
            else
            {
                Console.WriteLine("Ошибка: введено некорректное значение температуры.");
            }
        }
        else
        {
            Console.WriteLine("Ошибка: некорректный выбор. Пожалуйста, выберите 1 или 2.");
        }
    }
}*/
//zadanie 7
/*class Program
{
    static void Main()
    {
        Console.Write("Введите первое число: ");
        int firstNumber;
        while (!int.TryParse(Console.ReadLine(), out firstNumber))
        {
            Console.WriteLine("Ошибка: введите корректное целое число.");
        }

        Console.Write("Введите второе число: ");
        int secondNumber;
        while (!int.TryParse(Console.ReadLine(), out secondNumber))
        {
            Console.WriteLine("Ошибка: введите корректное целое число.");
        }

        int start = Math.Min(firstNumber, secondNumber);
        int end = Math.Max(firstNumber, secondNumber);

        Console.WriteLine($"Нормализованный диапазон: {start} - {end}");

        Console.WriteLine("Четные числа в указанном диапазоне:");

        for (int i = start; i <= end; i++)
        {
            if (i % 2 == 0)
            {
                Console.WriteLine(i);
            }
        }
    }
}*/
