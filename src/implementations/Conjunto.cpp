#include "../interfaces/Conjunto.h"
#include <cstddef>

Conjunto::Conjunto()
{
  size = 0;
  d = new double[1];
}

void Conjunto::Inserir(double k)
{
  if (Vazio()) 
  {
    d[0] = k;
  } 
  else
  {
    if (!Pertence(k))
    {
      double *novoConjunto = new double[size + 1];
      for (int n = 0; n < size; n++)
      {
        novoConjunto[n] = d[n];
      }
      novoConjunto[size] = k;
      d = novoConjunto;
    }
  }
  size++;
};

bool Conjunto::Pertence(double k)
{
  bool pertence = false;
  if (!Vazio())
  {
    for (int n = 0; n < size; n++)
    {
      if (d[n] == k)
      {
        pertence = true;
      }
    }
  }
  return pertence;
}

void Conjunto::Remover(double k)
{
  if (!Vazio())
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
        size--;
      }
    }
  }
}

bool Conjunto::operator==(Conjunto &x)
{
  bool igual = true;
  if (Vazio() != x.Vazio())
  {
    for (int n = 0; n < size; n++)
    {
      if (!x.Pertence(d[n]))
      {
        igual = false;
      }
    }
  }
  return igual;
}

Conjunto::~Conjunto()
{
  delete[] d;
  d = NULL;
  size = 0;
}

bool Conjunto::Vazio() 
{
  return size == 0;
}

void Conjunto::Imprimir() 
{
  if (Vazio())
  {
    std::cout << "Vazio" << std::endl;
  } 
  else
  {
    std::cout << std::endl;
    for (int n = 0; n < size; n++)
    {
      std::cout << d[n] << ", ";
    }
  }
}