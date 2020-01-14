// func(void) means that func must be called without any argument
extern void hello_from_cpp(void);

int main(int argc, char* argv[]) {
  hello_from_cpp();
  return 0;
}
