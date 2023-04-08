pkgname="openutils-heap_pair"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="heap-pair template class for C++."
arch=("x86_64" "i686")
conflicts=('openutils-heap_pair')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/heap-pair/main/heap-pair/heap-pair.hh")

sha512sums=(
	"23d447d847068d59fbfff7fcc03076ae848edc42f58568e786536df2d013f8956fab3e17085e6232c1c0ea9ddb96cb4ad3beb7bd2bfdacc2e44c60b85e732451")

package() {
	echo "heap-pair template class for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/heap-pair"
	cp "${srcdir}/heap-pair.hh" "${pkgdir}/usr/include/openutils/heap-pair/heap-pair.hh"
	echo "Done!"
}
