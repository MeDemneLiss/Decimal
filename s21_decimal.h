/* int [0,1,2] cодержат младшие, средние и старшие 32
 * бита 96-разрядного целого числа соответственно.
 *
 * int [3]
 * Биты с 16 по 23 должны содержать показатель степени от 0 до 28, который
 * указывает степень 10 для разделения целого числа;
 *
 * Бит 31 содержит знак; 0 означает
 * положительный, а 1 означает отрицательный.
 * 0000 0000 0000 0000 0000 0000 0000 0000 int[0] - младшие биты
 * 0000 0000 0000 0000 0000 0000 0000 0000 int[1] - средние биты
 * 0000 0000 0000 0000 0000 0000 0000 0000 int[2] - старшие биты
 * 0XXX XXXX 0000 0000 XXXX XXXX XXXX XXXX int[3] - коэфы и знак
 */
typedef struct {
  int bits[4];
} s21_decimal;

#define OK_rounders 0
#define calculation_error_rounders 1

/* Проверяем, если знаки у чисел одинаковые, складываем, в противном случае
 * отправляем в вычетание.
 * вход - 2 decimal слагаемых и указатель на decimal результат.
 * выход - код ошибки
 */
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/* Проверяем, если знаки у чисел одинаковые, вычетаем, в противном случае
 * отправляем в сложение.
 * вход - 2 decimal слагаемых и указатель на decimal результат.
 * выход - код ошибки
 */
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/*
 *здесь описание
 *
 *
 */
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/*
 *здесь описание
 *
 *
 */
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

/*
 *здесь описание
 *
 *
 */
int s21_is_less(s21_decimal, s21_decimal);
/*
 *на вход получает два децимала для сравнения, если первый меньше второго, то
 *возвращает 1, иначе 0 сперва сравнивает знак, после этого проверяет коэффицент
 *масштабирования, если он разный, то выравнивает после чего сравнивает
 *поинтово, начиная со старшего инта
 *
 */
int s21_is_less_or_equal(s21_decimal, s21_decimal);
/*
 *на вход получает два децимала для сравнения, если первый равен второму или
 *меньше него, то возвращает 1, иначе 0 по сути возвращает результат
 *s21_is_equal(s21_decimal, s21_decimal) или s21_is_less(s21_decimal,
 *s21_decimal)
 *
 */
int s21_is_greater(s21_decimal, s21_decimal);
/*
 *на вход получает два децимала для сравнения, если первый больше второго, то
 *возвращает 1, иначе 0 сперва сравнивает знак, после этого проверяет коэффицент
 *масштабирования, если он разный, то выравнивает после чего сравнивает
 *поинтово, начиная со старшего инта
 *
 */
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
/*
 *на вход получает два децимала для сравнения, если первый равен второму или
 *больше него, то возвращает 1, иначе 0 по сути возвращает результат
 *s21_is_equal(s21_decimal, s21_decimal) или s21_is_greater(s21_decimal,
 *s21_decimal)
 *
 */
int s21_is_equal(s21_decimal, s21_decimal);
/*
 *на вход получает два децимала для сравнения, если первый равен второму, то
 *возвращает 1, иначе 0 сперва сравнивает знак, после этого сравнивает
 *коэффицент масштабирования и наконец сравнивает поинтово начиная со старшего
 *инта
 */
int s21_is_not_equal(s21_decimal, s21_decimal);

/*
 *на вход получает два децимала для сравнения, если первый не равен второму, то
 *возвращает 1, иначе 0 по сути возвращает результат !(s21_is_equal(s21_decimal,
 *s21_decimal))
 *
 *
 */
int s21_from_int_to_decimal(int src, s21_decimal *dst);
/*
 *на входит принимает целое число src и указатель dst
 *преобразовывает тип int в decimal
 *возвращает 0 если преобразование прошло успешно, 1 если ошибка
 */
int s21_from_float_to_decimal(float src, s21_decimal *dst);
/*
 *на входит принимает число типа float src и указатель dst
 *преобразовывает тип float в decimal
 *возвращает 0 если преобразование прошло успешно, 1 если ошибка
 */
int s21_from_decimal_to_int(s21_decimal src, int *dst);
/*
 *на входит принимает decimal src и int dst
 *преобразовывает тип decimal в int
 *возвращает 0 если преобразование прошло успешно, 1 если ошибка
>>>>>>> develop_krazztra
 */
int s21_from_decimal_to_float(s21_decimal src, float *dst);

/*
 *на входит принимает decimal src и float dst
 *преобразовывает тип decimal в dst
 *возвращает 0 если преобразование прошло успешно, 1 если ошибка
 */
int s21_floor(s21_decimal value, s21_decimal *result);
/*Округляет value до ближайшего целого числа. Сначала вычисляется целая часть,
 *затем дробная. Если дробная часть равна 0.5 и целая часть нечетная или дробная
 *часть больше 0.5, то к целой части добавляется 1. Результат записывается в
 *result. Если округление успешно то возвращает код 0, если ошибка - 1.
 *
 */
int s21_round(s21_decimal value, s21_decimal *result);
/*
 *Возвращает целые часть value, дробная часть отбрасывается,
 *включая конечные нули. Результат записывается в result.
 *Если округление успешно то возвращает код 0, если ошибка - 1.
 *
 *
 */
int s21_truncate(s21_decimal value, s21_decimal *result);
/*
 *здесь описание
 *
 *
 */
int s21_negate(s21_decimal value, s21_decimal *result);
