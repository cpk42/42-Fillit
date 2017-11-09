#include "fillit.h"

int	find_sqrt(int n, int nb)
{
  if (n * n > nb)
    {
      return (0);
    }
  if (n * n == nb)
    {
      return (n);
    }
  else
    {
      return (find_sqrt(n + 1, nb));
    }
}

int	get_size(piece *lst)
{
  unsigned int size;
  unsigned int i;
  
  size = countpiece(&lst);
  size *= 4;
  i = 0;
  while (!i)
    {
      i = find_sqrt(1, size);
      size++;
    }
  return (i);
}
