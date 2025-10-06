function merge(intervals) {
  if (!intervals.length) return [];
  intervals.sort((a, b) => a[0] - b[0]);

  const merged = [intervals[0]];

  for (let i = 1; i < intervals.length; i++) {
    const last = merged[merged.length - 1];
    const [start, end] = intervals[i];

    if (start <= last[1]) {
      last[1] = Math.max(last[1], end);
    } else {
      merged.push(intervals[i]);
    }
  }

  return merged;
}

console.log(merge([[1,3],[2,6],[8,10],[15,18]]));
// Output: [[1,6],[8,10],[15,18]]
