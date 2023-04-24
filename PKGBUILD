pkgname="openutils-vector"
pkgver="2.0.0"
pkgrel="4"
pkgdesc="VECTOR : The Resizable Array Library"
arch=("x86_64" "i686")
conflicts=('openutils-vector')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/vector/main/vector/vector.hh")
sha512sums=("bb5233dbdc53900172d34a6a77ffd07851c0f7aa049fc9844c3714af7d85d843657ce0b6292612a8fadbfb07df1a32695383546adcd79ad20f6b8ff6779718d0")

package() {
	echo "VECTOR : The Resizable Array Library"
	mkdir -p "${pkgdir}/usr/include/openutils/vector"
	cp "${srcdir}/vector.hh" "${pkgdir}/usr/include/openutils/vector/vector.hh"
	echo "Done!"
}