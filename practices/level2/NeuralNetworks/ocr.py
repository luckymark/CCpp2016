from PIL import Image
import numpy as np
from collections import Counter
from functools import reduce


def load_data(filename):
    dataset = np.empty((0, 64), dtype=int)
    labels = np.empty((0, 1), dtype=int)
    with open(filename, 'r') as f:
        for line in f:
            line = line.strip()
            raw = np.array([int(s) for s in line.split(',')])
            data = raw[:-1]
            label = raw[-1:]
            dataset = np.append(dataset, [data], axis=0)
            labels = np.append(labels, label)
    return dataset, labels


def knn(input_array, dataset, labels, k):
    input_matrix = np.tile(input_array, (len(dataset), 1))
    variance_matrix = ((dataset - input_matrix) ** 2).sum(axis=1)
    sorted_label_index = list(variance_matrix.argsort())
    label_counter = Counter([labels[i] for i in sorted_label_index[:k]])
    most_likey_nums = label_counter.most_common(3)
    return most_likey_nums


def load_img(imgname):
    img = Image.open(imgname)
    img = img.convert('1')
    raw_array = img.getdata()
    cooked_array = np.array([int(16 * (255 - i) / 255) for i in raw_array])
    return cooked_array


def main():
    dataset, labels = load_data('optdigits.tra')
    input_array = load_img('input.png')
    results = knn(input_array, dataset, labels, 5)
    total = results[0][1] if len(results) == 1 else reduce(
        lambda x, y: x + y[1], results, 0)
    for r in results:
        print('The number is %r with %r %% posibility.' %
              (r[0], r[1] / total * 100))


if __name__ == '__main__':
    main()
