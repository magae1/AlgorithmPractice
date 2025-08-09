import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Course {
    public final int s;
    public final int t;
    
    public Course(int s, int t) {
        this.s = s;
        this.t = t;
    }
    
    @Override
    public String toString() {
        return "(s,t) = (" + s + "," + t + ")";
    }
}

class CourseComparator implements Comparator<Course> {
    @Override
    public int compare(Course a, Course b) {
        if (a.s == b.s) {
            return (a.t - a.s) - (b.t - b.s);
        }
        return a.s - b.s;
    }
}


public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		int n = Integer.parseInt(bf.readLine());
		
		StringTokenizer st = null;
		PriorityQueue<Course> qu = new PriorityQueue<>(new CourseComparator());
		for (int i = 0; i < n; i++) {
		    st = new StringTokenizer(bf.readLine(), " ");
		    int s = Integer.parseInt(st.nextToken());
		    int t = Integer.parseInt(st.nextToken());
		    qu.add(new Course(s, t));
		}
		
		PriorityQueue<Integer> intQu = new PriorityQueue<>();
		Course fstCourse = qu.poll();
		intQu.add(fstCourse.t);
		
		while(!qu.isEmpty()) {
		    Course cu = qu.poll();
		    Integer minTime = intQu.peek();
		    if (minTime <= cu.s) {
		        intQu.poll();
		    }
		    intQu.add(cu.t);
		}
		
		System.out.println(intQu.size());
	}
}