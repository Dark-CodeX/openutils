pkgname="openutils-vector"
pkgver="2.0.0"
pkgrel="4"
pkgdesc="VECTOR : The Resizable Array Library"
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("GNU GPL v3.0")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("5bb79383df0233846847f1a286b767c06d149c63460434dec540aee8cfec48254cfd3c63f84861619714f956ebf3ace2db810a2257edd33d41d9d25ed74b6d8a")

package() {
	echo "VECTOR : The Resizable Array Library"
	mkdir -p "${pkgdir}/usr/include/openutils/vector"
	cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
	echo "Done!"
}