package RPG;

public class Main {
	public static void main(String args[]) {
		Role hehe = new Role();
		Role b = new Role ("我是小菜機", 100, 10, 10, 0, "physics");
		
		for (int i = 0; i < 10; i++) {
			hehe.attack(b);
		}
	}
}
