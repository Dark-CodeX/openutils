pkgname="openutils-heap_pair"
pkgver="1.0.1"
pkgrel="1"
pkgdesc="heap-pair template class for C++."
arch=("x86_64" "i686")
conflicts=('openutils-heap_pair')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/heap-pair/main/heap-pair/heap-pair.hh")

sha512sums=("c88bebf74bfe26b90a1f8bd0e13a93ee3d4f9181557ece3844795f63553b9786d58996a96406630fa16b9d08356787d4361ff21e43dc0ae715a60f1de28b0093")

package() {
	echo "heap-pair template class for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/heap-pair"
	cp "${srcdir}/heap-pair.hh" "${pkgdir}/usr/include/openutils/heap-pair/heap-pair.hh"
	echo "Done!"
}
