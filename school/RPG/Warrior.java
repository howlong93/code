package RPG;

public class Warrior extends Role {
	private int armor;
	private int smash;
	
	public Warrior() {
		super();
		armor = 20;
		smash = 20;
	}
	
	public Warrior (String nm, int l, int m, int a, int d, String at, int arm, int sm) {
		super (nm, l, m, a, d, at);
		armor = arm;
		smash = sm;	
	}
	
	public int getArmor () {return armor;}
	public int getSmash () {return smash;}
	
	public void bixagi (Role r) {
		
	}
}
