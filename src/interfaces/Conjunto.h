class Conjunto {
  public:
  Conjunto();
  void Inserir(double k);
  void Remover(double k);
  bool Pertence(double k);
  bool operator==(Conjunto& x);
  ~Conjunto();
  private:
  double * d;
  int size = 1;
};
