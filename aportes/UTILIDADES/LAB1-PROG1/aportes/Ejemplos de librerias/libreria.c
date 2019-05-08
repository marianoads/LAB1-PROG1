int obtenerMaximo(int x , int y , int z)
{
    int mayor;

    if(x >= y && x >= z)
    {
        mayor = x;
    }
    else if(y >= x && y >= z)
    {
        mayor = y;
    }
    else if(z >= x && z >= y)
    {
        mayor = z;
    }

    return mayor;
}

