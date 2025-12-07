/* Compensation
	Assuming the outcome of grabbing forks (mutex locking) is random, we can
	introduce a rule where philos that are fine relinquish the fork, while those
	near death hold on to it. This can introduce a deadlock, but considering
	that death should be avoided at all costs, it's not a problem.
*/