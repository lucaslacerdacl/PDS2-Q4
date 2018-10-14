#include "../interfaces/Conjunto.h"

Conjunto::Conjunto()
{
  d = new double[size];
}

void Conjunto::Inserir(double k)
{
  if (!Pertence(k))
  {
    double *novoConjunt = new double[size + 1];
    for (int n = 0; n < size; n++)
    {
      novoConjunt[n] = d[n];
    }
    novoConjunt[size + 1] = k;
    d = novoConjunt;
  }
};

bool Conjunto::Pertence(double k)
{
  bool pertence = false;
  for (int n = 0; n < size; n++)
  {
    if (d[n] == k)
    {
      pertence = true;
    }
  }
  return pertence;
}

void Conjunto::Remover(double k)
{
  for (int i = 0; i < size; i++)
  {
    if (d[i] == k)
    {
      for (; i < size - 1; i++)
      {
        d[i] = d[i + 1];
      }

      d[size - 1] = 0;
      size = size - 1;
    }
  }
}

bool Conjunto::operator==(Conjunto &x)
{
  bool igual = true;
  for (int n = 0; n < size; n++)
  {
    if (!x.Pertence(d[n]))
    {
      igual = false;
    }
  }
  return igual;
}

Conjunto::~Conjunto()
{
  delete[] d;
}