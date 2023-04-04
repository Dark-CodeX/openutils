pkgname="openutils-heap_pair"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="heap-pair template class for C++."
arch=("x86_64" "i686")
conflicts=('openutils-heap_pair')
depends=(gcc)
license=("MIT")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/heap-pair/main/heap-pair/heap-pair.hh")

sha512sums=(
	"a236141e8b113d81e780754008221e3d3a3aa5acada62a7123bd3f86d96be72ff5af2bc5a1bc7c3c3c3715536301d957707f6039cfb04904bd9e9e0f5ed2865b")

package() {
	echo "heap-pair template class for C++."
	mkdir -p "${pkgdir}/usr/include/openutils/heap-pair"
	cp "${srcdir}/heap-pair.hh" "${pkgdir}/usr/include/openutils/heap-pair/heap-pair.hh"
	echo "Done!"
}
