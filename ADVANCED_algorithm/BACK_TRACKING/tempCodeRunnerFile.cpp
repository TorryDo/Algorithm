unt = 0;

    for (auto v : sv)
    {
        int sum = 0;
        for (auto i : v)
        {
            sum += i;
        }
        if (sum == k)
            count++;
    }