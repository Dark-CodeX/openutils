pkgname="openutils-heap_pair"
pkgver="1.2.0"
pkgrel="1"
pkgdesc="HEAP-PAIR : The Pair Management Library"
arch=("x86_64" "i686")
conflicts=('openutils-heap_pair')
depends=(gcc)
license=("GNU GPL v3.0")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/heap-pair/main/heap-pair/heap-pair.hh")

sha512sums=("14851260b5c23309afcc9506a8411c4d3d27bd281d62a6908884338263e8d946a4dc99172b22f0633a400eb21155e5dbd5e9227540673146f27dedc6b2fd288b")

package() {
	echo "HEAP-PAIR : The Pair Management Library"
	mkdir -p "${pkgdir}/usr/include/openutils/heap-pair"
	cp "${srcdir}/heap-pair.hh" "${pkgdir}/usr/include/openutils/heap-pair/heap-pair.hh"
	echo "Done!"
}
