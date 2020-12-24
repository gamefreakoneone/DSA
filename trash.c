void InfixtoPostfix(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");
    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(st, source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top !=–1) && (st[top] != '('))
            {
                target[j] = pop(st);
                j++;
            }
            if (top ==–1)
            {
                printf("\n INCORRECT EXPRESSION");
                exit(1);
            }
            temp = pop(st); //remove left parenthesis
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '–' || source[i] == '*' ||
                 source[i] == '/' || source[i] == '%')
        {
            while ((top !=–1) && (st[top] != '(') && (getPriority(st[top]) > getPriority(source[i])))
            {
                target[j] = pop(st);
                j++;
            }
            push(st, source[i]);
            i++;
        }
        else
            236 Data Structures Using C
            {
                printf("\n INCORRECT ELEMENT IN EXPRESSION");
                exit(1);
            }
    }
    while ((top !=–1) && (st[top] != '('))
    {
        target[j] = pop(st);
        j++;
    }
    target[j] = '\0';
}