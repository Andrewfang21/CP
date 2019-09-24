import java.util.Scanner;

public class MenggambarPegunungan {

	public static void drawStar(int starCount) {
		if (starCount == 1) {
			System.out.println("*");
			return;
		}
		else {
			drawStar(starCount - 1);
			for (int i = 1; i <= starCount; i ++)
				System.out.print("*");
			System.out.println();
			drawStar(starCount - 1);
		}
	}
	
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		int N = scan.nextInt();
		
		drawStar(N);
	}
}