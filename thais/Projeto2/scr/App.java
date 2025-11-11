public class App {
    public static void main(String[] args) throws Exception {
        System.out.println("Hello, World!");

        Carro carro = new Carro("Volvo", "AMO-2005", "Vermelho", "2005", "Thais");
        carro.exibeDadosCarro();

        Moto moto = new Moto("Honda", "GINA-666", "Verde Musgo", "2007", "Thais");
        moto.exibeDadosMoto();
    }
}
