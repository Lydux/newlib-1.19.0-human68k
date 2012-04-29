void
__main (void)
{
  static int initialized;

  if (! initialized)
    {
      typedef void (*pfunc) ();
      extern pfunc __ctors_start[];
      extern pfunc __ctors_end[];
      pfunc *p;

      initialized = 1;
      for (p = __ctors_end; p > __ctors_start; )
        (*--p)();

    }
}
