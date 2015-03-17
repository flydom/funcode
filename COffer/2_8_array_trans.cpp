// 旋转数组

int MinInOrder(int* numbers, int index1, int index2)
{
    int i = index1;
    int key = numbers[index1];

    while (i <= index2)
    {
        if (numbers[i] < key)
        {
            key = numbers[i];
        }

        i++;
    }

    return key;
}


int Min(int* numbers, int length)
{
    int low = 0;
    int high = length - 1;
    int mid = low;

    if(numbers == NULL || length <= 0)
        throw new std::exception("Invalid parameters");

    while (numbers[low] >= numbers[high])
    {
        if (high - low == 1)
        {
            mid = high;
            break;
        }

        mid = (low + high) / 2;
        if (numbers[low] == numbers[mid] &&
            numbers[mid] == numbers[high])
        {
            return MinInOrder(numbers, low, high);
        }
        
        if (numbers[mid] >= numbers[low])
        {
            low = mid;
        }
        else if (numbers[mid] <= numbers[high])
        {
            high = mid;
        }
    }
    
    return numbers[mid];
}