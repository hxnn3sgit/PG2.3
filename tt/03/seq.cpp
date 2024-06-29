#include <iostream>
#include <cmath>

using namespace std;

struct sequence {
	int min;
	int max;
	int step;
	int current;
};

struct transform_sequence {
	sequence *seq;
	float (*transform) (int);
};

sequence make_sequence(int min, int max, int step);
bool has_next(const sequence *seq);
int next(sequence *seq);

transform_sequence make_transform_sequence(sequence *seq, int (*transform) (int));

bool has_next(const transform_sequence *tf_seq);
int next(transform_sequence *seq);
float squared(int i);


int main(int argc, char **argv) {
	if (argc == 4) {
		int min, max, step;
		min = atoi(argv[1]);
		step = atoi(argv[2]);
		max = atoi(argv[3]);

		sequence seq = make_sequence(min, max, step);
		transform_sequence tf_seq;
		tf_seq = make_transform_sequence(&seq, squared);
		//jetzt gibt es eine tf_seq, die einen *seq und einen funktionspointer enthält
		
		while (has_next(&tf_seq)) {
			cout << next(&tf_seq) << endl;
		}
	} else {
		cout << "Falsche Parameter uebergeben; Benoetigte Parameter: Start, Step, Ende\n";
		return(EXIT_FAILURE);
	}
	return 0;
}

sequence make_sequence(int min, int max, int step) {
	sequence seq;

	seq.min = min;
	seq.step = step;
	seq.max = max;
	seq.current = min;

	return seq;
}

transform_sequence make_transform_sequence(sequence *seq, int (*transform) (int)) {
	transform_sequence tf_seq;
	tf_seq.seq = seq;
	tf_seq.transform = transform;

	return tf_seq;
		
}

bool has_next(const sequence *seq) {
	if ( seq->current <= seq->max) 
		return true;
	else
		return false;
}

int next(sequence *seq) {
	int current = seq->current;
	seq->current += seq->step;
	return current;
}

bool has_next(const transform_sequence *tf_seq) {
	if ( tf_seq->seq->current <= tf_seq->seq->max) 
		return true;
	else
		return false;
}

int next(transform_sequence *tf_seq) {
	int current = tf_seq->seq->current;
	tf_seq->seq->current += tf_seq->seq->step;
	return squared(current);
}

float squared(int i) {
	return sqrt(i * i / 3);
}
