#!/bin/python
#-*- coding:utf-8 -*-

from collections import deque

class istream:
	ibuf = deque()
	def next_str(self):
		while len(self.ibuf) == 0:
			self.ibuf.extendleft(raw_input().split())
		return self.ibuf.pop()
	def next_int(self):
		return int(self.next_str())
	
def main():
	"input"
	cin = istream();
	n = cin.next_int()
	m = [cin.next_int() for i in xrange(n)]
	"count and sort"
	d = {}
	for k in m:
		d[k] = d.get(k,0)+1
	l = sorted([(k,v) for (k,v) in d.iteritems() if v>1], key = (lambda i:i[1]), reverse = True)
	"output"
	for i in l:
		print "%d: %d"%(i[0],i[1])
	
if __name__ == '__main__':
	main()

