public class App {
    public static void main(String[] args) throws Exception {
        //System.out.println("Hello, World!");

        //Scanner sc = new Scanner(System.in);

        Endereco end = new Endereco("rua", "Vitoria", "ES", "29060160");
        // System.out.println(end.getLogradouro());
        // System.out.println(end.getCidade());
        // System.out.println(end.getEstado());
        // System.out.println(end.getCep());

        // Endereco end2 = new Endereco("avenida", "Serra", "ES", "29550099");
        // System.out.println(end2.getLogradouro());
        // System.out.println(end2.getCidade());
        // System.out.println(end2.getEstado());
        // System.out.println(end2.getCep());

        Cliente cliente = new Cliente("Thais", "10000000000", "99909909090");
        cliente.setEndereco(end);
        System.out.println(cliente.getEndereco().getLogradouro());
        System.out.println(cliente.getEndereco().getCidade());
        System.out.println(cliente.getEndereco().getEstado());
        System.out.println(cliente.getEndereco().getCep());
        System.out.println(cliente.getNome());
        System.out.println(cliente.getCPF());
        System.out.println(cliente.getTelefone());

    }
}
