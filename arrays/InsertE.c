void insertElement()
{
    int position,value,c,n;
    int array[20];
    printf("Please enter the location where you want to insert an new element\n");
    scanf("%d", &position);

    printf("Please enter the value\n");
    scanf("%d", &value);

    for (c = n - 1; c >= position - 1; c--)
        array[c + 1] = array[c];

    array[position - 1] = value;
}