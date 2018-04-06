public class GravityCalculator {
	
	static double returnFinalPosition(double time, double gravity, double initialVelocity, 
			double initialPosition ) {
			double finalPos;
			finalPos = (0.5 * gravity*time*time) + (initialVelocity*time)
						+ (initialPosition);
			return finalPos;
	}
	public static void main (String arguments[]){
		double  gravity = -9.81;
		double initVelocity = 0.0;
		double fallingTime = 10.0;
		double initialPosition = 0.0;
		double finalPosition = 0.0;
		finalPosition = returnFinalPosition(fallingTime,gravity,initVelocity,initialPosition);
		System.out.println("The Object's position after " + fallingTime + " seconds is "
						+ finalPosition +" m.");
	}
	
}  
