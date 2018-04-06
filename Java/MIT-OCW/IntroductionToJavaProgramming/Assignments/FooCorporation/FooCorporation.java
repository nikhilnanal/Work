
public class FooCorporation {
	public static void main(String args[]) {
		
		Employee E1 = new Employee("Employee1",7.5,35);
		Employee E2 = new Employee("Employee2",8.20,47);
		Employee E3 = new Employee("Employee3",10.0,73);
	
		System.out.println(E1.getSalary() > 0 ? "The Salary of " + E1.getName() + "is $ " + E1.getSalary():"Error, No pay for you! Worked more than 60 hrs");
		System.out.println(E2.getSalary() > 0 ? "The Salary of " + E2.getName() + "is $ " + E2.getSalary():"Error, No pay for you! Worked more than 60 hrs");
		System.out.println(E3.getSalary() > 0 ? "The Salary of " + E3.getName() + "is $ " + E3.getSalary():"Error, No Pay for you! Worked more than 60 hrs");
	}

}

class Employee {
	private String Name;
	private double Basepay;
	private int hoursWorked;
	
	Employee(String Name, double Basepay, int hoursWorked){
		this.Name = Name;
		this.Basepay = Basepay;
		this.hoursWorked = hoursWorked;
	}
	String getName(){
		return  this.Name;
	}
	
	double getSalary() {
		
		double Salary = 0;
		if (this.hoursWorked > 60)
			Salary = -1;
		else {
			int Extrahours = ((this.hoursWorked-40) > 0 )? (this.hoursWorked-40):0;	
			Salary = (hoursWorked * this.Basepay) + (1.5 * this.Basepay * Extrahours);	
		}
		return Salary;
		
	}
	
}
