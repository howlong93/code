package RPG;

public class Role {
	private String name;
	private int life;
	private int mana;
	private int atk;
	private int def;
	private String atkType;
	
	public Role () {
		life = 100;
		mana = 100;
		atk = 20;
		def = 10;
		atkType = "physics";
		name = "Noob";
	}
	
	public Role (String nm, int lf, int mn, int a, int d, String at) {
		life = lf;
		mana = mn;
		atk = a;
		def = d;
		if (at.equals("physics") || at.equals("spells")) {
			atkType = at;
		}
		else {
			atkType = "physics";
		}
		name = nm;
	}
	
	public String getName() {return name;}
	public int getLife() {return life;}
	public int getMana() {return mana;}
	public int getAtk() {return atk;}
	public int getDef() {return def;}
	public String getAT() {return atkType;}
	
	public void attack (Role r) {
		r.hurt(this);
	}
	/*
	public void beAttacked (Role r) {
		int damage = r.getDamage();
		hurt (damage);
	}
	*/
	public void hurt (Role r) {
		int d = r.getAtk()-def;
		if (d > 0 && life > 0) {
			life -= d;
			System.out.println (r.name + " is attacking " + name + "\n" + name + " life: " + life);
			if (life <= 0) System.out.println (name + " is dead! qq");
		}
		else if (life <= 0) {
			System.out.println (name + " is already dead!!");
		}
	}
}
