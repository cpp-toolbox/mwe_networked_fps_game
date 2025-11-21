import sys
import datetime
import matplotlib.pyplot as plt

if len(sys.argv) < 3:
    print("Usage: python plot_times.py <filename> <frequency_hz>")
    sys.exit(1)

filename = sys.argv[1]
try:
    frequency_hz = float(sys.argv[2])
except ValueError:
    print("Error: frequency_hz must be a number")
    sys.exit(1)

# Read times
times = []
with open(filename) as f:
    for line in f:
        ts = line.split("]")[0].strip("[] ").strip()
        t = datetime.datetime.strptime(ts, "%H:%M:%S.%f")
        times.append(t)

# Plot event arrivals
plt.plot(times, range(len(times)), marker=".", linestyle="None")
plt.gcf().autofmt_xdate()  # pretty formatting
plt.xlabel("Time")
plt.ylabel("Event index")
plt.title(f"Event times from {filename}")

# Draw vertical lines at the reference frequency
start_time = times[0]
end_time = times[-1]
delta = datetime.timedelta(seconds=1 / frequency_hz)
vline_time = start_time

while vline_time <= end_time:
    plt.axvline(vline_time, color="gray", alpha=0.3, linewidth=0.8)
    vline_time += delta

plt.show()
