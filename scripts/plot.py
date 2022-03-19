import numpy as np
import matplotlib.pyplot as plt
import matplotlib.colors as colors
import matplotlib.patches as mpatches

def get_legend(file):
    # legend index: freespace, obstacle, start, goal, path, obstacle_path, collision
    legend_map = {'freespace' : 0,
                  'obstacle' : 0,
                  'start' : 0,
                  'goal' : 0,
                  'planned_path' : 0,
                  'obstacle_path' : 0,
                  'collision' : 0}
    legend_str = ['freespace',
                  'obstacle',
                  'start',
                  'goal',
                  'planned_path',
                  'obstacle_path',
                  'collision']
    line_str = file.readline()
    line = line_str.split(' ')
    legend_arr = []
    for s in line:
        legend_arr.append(int(s))
    for i in range(min(len(legend_arr), len(legend_map))):
        legend_map[legend_str[i]] = legend_arr[i]
    return legend_map

def get_grid_map_body(file):
    next(file)
    rows_str = []
    rows = []
    lines = file.readlines()
    for line in lines:
        rows_str.append(line.split(' '))
    for row_str in rows_str:
        tmp_row = []
        for r in row_str:
            tmp_row.append(int(r))
        rows.append(tmp_row)
    return rows

def parse_txt_file(file_name):
    parsed_data = []
    file = open(file_name,'r')
    legend_map = get_legend(file)
    body = get_grid_map_body(file)
    file.close()
    return legend_map, body

def parse(file_name):
    legend, body = parse_txt_file(file_name)
    return legend, body

def def_std_plot(data):
    plt.imshow(data)
    plt.show()

def plot(legend, data):
    cmap = colors.ListedColormap(['White',
                                  'Magenta',
                                  'Red',
                                  'Purple',
                                  'Yellow',
                                  'Black',
                                  'Green',
                                  'Cyan',
                                  'Blue',
                                  'Grey'])
    plt.pcolor(data[::-1], cmap=cmap, edgecolors='k', linewidths=1)
    white_patch = mpatches.Patch(color='white', label='freespace')
    red_patch = mpatches.Patch(color='red', label='obstacle')
    yellow_patch = mpatches.Patch(color='yellow', label='start')
    green_patch = mpatches.Patch(color='green', label='goal')
    blue_patch = mpatches.Patch(color='blue', label='path')
    grey_patch = mpatches.Patch(color='grey', label='obstacle_path')
    magenta_patch = mpatches.Patch(color='magenta', label='collision')
    cyan_patch = mpatches.Patch(color='cyan', label='unknown')
    purple_patch = mpatches.Patch(color='purple', label='unknown')
    black_patch = mpatches.Patch(color='black', label='unknown')
    # plt.legend(handles=[white_patch, red_patch, yellow_patch, green_patch, blue_patch, grey_patch, magenta_patch])
    plt.show()

def main():
    legend, body = parse('../gen/grid_map_output.txt')
    plot(legend, body)

if __name__ == "__main__":
    main()