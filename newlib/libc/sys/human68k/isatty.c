/* 1 = stdin
 * 2 = stdout
 * 3 = stderr
 * 4 = stdaux
 * 5 = stdprn
 */

int
isatty(int file)
{
  return file <= 5;
}

