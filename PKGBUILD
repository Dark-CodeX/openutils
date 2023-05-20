pkgname="openutils-chunkio"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="CHUNKIO : The Performant I/O Library"
arch=("x86_64" "i686")
conflicts=('openutils-chunkio')
depends=(gcc)
license=("GNU GPL v3.0")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/chunkio/main/chunkio/chunkio_bytes_reader.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/chunkio/main/chunkio/chunkio_lines_reader.hh"
	"https://raw.githubusercontent.com/Dark-CodeX/chunkio/main/chunkio/chunkio_writer.hh")

sha512sums=(
	"7658215dbef10de7deb448219caa684e58cdbc56aeb0fbd301fca301cfb77b1cb2073af3d4d8fa66f13312312007b6964493c656e62f64970b603275ca89b68e"
	"221da63962fc9c681190d64857d7b4616708415204844ea17c5664044b1ddcacd8fd12ebdbc69cd940c2ae6b5621189de77921ef7fad809b9b844468fc2830e5"
	"0b88be295000cb872d6a6c7c2f937e6f002d1ca4093ac27da357d6d173b885f531cf62ce739abb99b92fede9b560ac0a65b7ba20d3aeb129833a523a40ca62b2")

package() {
	echo "CHUNKIO : The Performant I/O Library"
	mkdir -p "${pkgdir}/usr/include/openutils/chunkio"
	cp "${srcdir}/chunkio_bytes_reader.hh" "${pkgdir}/usr/include/openutils/chunkio/chunkio_bytes_reader.hh"
	cp "${srcdir}/chunkio_lines_reader.hh" "${pkgdir}/usr/include/openutils/chunkio/chunkio_lines_reader.hh"
	cp "${srcdir}/chunkio_writer.hh" "${pkgdir}/usr/include/openutils/chunkio/chunkio_writer.hh"
	echo "Done!"
}
