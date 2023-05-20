pkgname="openutils-vector"
pkgver="2.0.0"
pkgrel="4"
pkgdesc="VECTOR : The Resizable Array Library"
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("GNU GPL v3.0")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("0b2d4c91b3f308c49dd01d7af58db5532e7c7a3506ffc52a7542b9803551f0d055e9358617bc4b9e438df4b69e19e6299639b85798d09ac72869e0cb56f0c7e5")

package() {
	echo "VECTOR : The Resizable Array Library"
	mkdir -p "${pkgdir}/usr/include/openutils/vector"
	cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
	echo "Done!"
}