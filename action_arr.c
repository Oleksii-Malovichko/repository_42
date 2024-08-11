#include <stdio.h>
/* pop, append_int, in, print_arr_int, print_arr_char*/
// удаление элемента массива по индексу (если есть) или удаление последнего элемента (NULL в качестве аргумента индекса)
int    pop_int(int *arr, int rm_index, int *size)
{
    int index;

	if (rm_index >= *size || rm_index < -1)
	{
		return (0);
	}
    if (rm_index >= 0 && rm_index < *size) // удалить элемент по заданному индексу
    {
        index = rm_index;
        while (index < *size - 1)
        {
            arr[index] = arr[index+1];
            index++;
        }
        (*size)--;
    }
    if (rm_index == -1) // удаление посленего элемента
    {
        arr[*size - 1] = arr[*size];
        (*size)--;
    }
	return (1);
}

int	pop_char(char *str, int rm_index)
{
	int	index;
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	if (rm_index > len || rm_index < -1)
	{
		return (0);
	}
	if (rm_index >= 0)
	{
		index = rm_index;
		while (index < len - 1)
		{
			str[index] = str[index + 1];
			index++;
		}
		str[index] = str[index + 1];
	}
	if (rm_index == -1)
	{
		while (str[len] != '\0')
		{
			len++;
		}
		str[len-1] = str[len];
	}
	return (1);
}

int    append_int(int *arr, int add_item, int a_index, int *size)
{
    int index;
    int end; 
	if (a_index >= *size || a_index < -1)
	{
		return (0);
	}
    if (a_index == -1) // добаление элемента только назад
    {
        index = *size;
        (*size)++;
        arr[index] = add_item;
    }
    else // добавление элемента по индексу
    {
        (*size)++;
        index = a_index;
        end = *size - 1;
        while (end > index)
        {
            arr[end] = arr[end-1];
            end--;
        }
        arr[end] = add_item;
    }
	return (1);
}

int	append_char(char *str, char add_item, int a_index)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	if (a_index > len || a_index < -1)
	{
		return 0;
	}
	if (a_index == -1)
	{
		str[len] = str[len + 1];
		str[len] = add_item;
	}
	else
	{
		int static_len = len;
		str[static_len] = str[static_len+1];
		while (len > a_index)
		{
			str[len] = str[len - 1];
			len--;
		}
		str[a_index] = add_item;
	}
	return (1);
}

int	in_int(int *arr, int item, int size)
{
    int index;

    index = 0;
    while (index < size)
    {
        if (arr[index] == item)
        {
            return (1);
        }
        index++;
    }
    return (0);
}

int	in_char(char *str, char item)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == item)
		{
			return (1);
		}
		index++;
	}
	return (0);
}

void    arr_print(int *arr, int size)
{
    int index;

    index = 0;
    while (index < size)
    {
        printf("%d\n", arr[index]);
        index++;
    }
}

int main(void)
{
    int arr[] = {1,2,3,4,5};
    int size = (int)(sizeof arr / sizeof(int));
    int *size_p = &size;
    pop_int(arr, 2, size_p);

    arr_print(arr, size);

    append_int(arr, 10, 2, size_p);
    printf("-----------\n");
    append_int(arr, 200, 3, size_p);
    pop_int(arr, -1, size_p);
    arr_print(arr, size);

	char str[] = "hello, world";
	if (in_char(str, 'j'))
	{
		printf("Symbol is in str\n");
	}
	else
	{
		printf("Symbol is not in str\n");
	}
	printf("%s\n", str);
	pop_char(str, -1);
	printf("%s\n", str);

	append_char(str, 'd', -1);
	printf("%s\n", str);

}
